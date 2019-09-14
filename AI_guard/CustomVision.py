from azure.cognitiveservices.vision.customvision.prediction import CustomVisionPredictionClient
import cv2
import numpy as np
import os

def CV(fname,img):
    fname = fname[:fname.find('.')] + '.jpg'
    cv2.imwrite(fname, img)
    ENDPOINT = "https://southcentralus.api.cognitive.microsoft.com"
    predictor = CustomVisionPredictionClient("74845b27d7b747f7b3f9f85f4515be96", endpoint=ENDPOINT)
    with open(fname, mode="rb") as test_data:
        results = predictor.detect_image("ac90b148-4334-49b3-921c-d08e8da2b5e4", "findhole",test_data)
    for prediction in results.predictions:
        if prediction.probability >= 0.5:
            bd = prediction.bounding_box
            cv2.rectangle(img, (int(bd.width * img.shape[1]) + int(bd.left * img.shape[1]), int(bd.height * img.shape[0]) + int(bd.top * img.shape[0])), (int(bd.left * img.shape[1]), int(bd.top * img.shape[0])), (0, 0, 255), 2)

    with open(fname, mode="rb") as test_data:
        results = predictor.detect_image("729bf71b-467f-4c8f-988c-ec06e060a2e4", "findLP", test_data)
    for prediction in results.predictions:
        if prediction.probability >= 0.5:
            bd = prediction.bounding_box
            cv2.rectangle(img, (int(bd.width * img.shape[1]) + int(bd.left * img.shape[1]), int(bd.height * img.shape[0]) + int(bd.top * img.shape[0])), (int(bd.left * img.shape[1]), int(bd.top * img.shape[0])), (0, 0, 255), 2)
    return img