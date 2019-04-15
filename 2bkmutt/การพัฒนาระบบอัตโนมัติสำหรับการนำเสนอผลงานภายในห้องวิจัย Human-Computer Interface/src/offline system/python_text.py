from __future__ import division
import cv2
import time
import sys
import paho.mqtt.client as mqtt


def detectFaceOpenCVDnn(net, frame):
    frameOpencvDnn = frame.copy()
    blob = cv2.dnn.blobFromImage(frameOpencvDnn, 1.0, (300, 300), [104, 117, 123], False, False)

    net.setInput(blob)
    detections = net.forward()
    a = 0

    for i in range(detections.shape[2]):
        confidence = detections[0, 0, i, 2]

        if confidence > conf_threshold:
            a = a + 1


    if a >= 1 :
        f = open("Data.txt", "w")
        f.write(str(a))
        f.close()
    else:

        f = open("Data.txt", "w")
        f.write("0")
        f.close()

if __name__ == "__main__" :

    DNN = "TF"
    if DNN == "CAFFE":
        modelFile = "models/res10_300x300_ssd_iter_140000_fp16.caffemodel"
        configFile = "models/deploy.prototxt"
        net = cv2.dnn.readNetFromCaffe(configFile, modelFile)
    else:
        modelFile = "models/opencv_face_detector_uint8.pb"
        configFile = "models/opencv_face_detector.pbtxt"
        net = cv2.dnn.readNetFromTensorflow(modelFile, configFile)

    conf_threshold = 0.7

    source = 0
    if len(sys.argv) > 1:
        source = sys.argv[1]

    cap = cv2.VideoCapture(source)
    hasFrame, frame = cap.read()

    vid_writer = cv2.VideoWriter('output-dnn-{}.avi'.format(str(source).split(".")[0]),cv2.VideoWriter_fourcc('M','J','P','G'), 15, (frame.shape[1],frame.shape[0]))

    frame_count = 0
    tt_opencvDnn = 0
    while(1):
        hasFrame, frame = cap.read()
        if not hasFrame:
            break

        frame_count += 1

        t = time.time()
        detectFaceOpenCVDnn(net,frame)

        k = cv2.waitKey(10)
        if k == 27:
            break
    cv2.destroyAllWindows()
    vid_writer.release()