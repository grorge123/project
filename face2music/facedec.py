import http.client, urllib.request, urllib.parse, urllib.error, base64
import json

headers = {
    'Content-Type': 'application/octet-stream',
    'Ocp-Apim-Subscription-Key': 'cf16983fd22f46f8bcb02cb519e9785e',
}

params = urllib.parse.urlencode({
    'returnFaceId': 'true',
    'returnFaceAttributes': 'emotion',
    'recognitionModel': 'recognition_04',
    'detectionModel': 'detection_01',
})
def reqfaced(file):
    try:
        conn = http.client.HTTPSConnection('face-emotion-grorge.cognitiveservices.azure.com')
        # conn.request("POST", "/face/v1.0/detect?%s" % params, "{\"url\":\"https://transcode-v2.app.engoo.com/image/fetch/f_auto,c_lfill,w_800,h_600,dpr_3/https://assets.app.engoo.com/images/0CUB4KUELv6QJiDgFHJfU6.jpeg\"}", headers)
        conn.request("POST", "/face/v1.0/detect?%s" % params, file, headers)
        response = conn.getresponse()
        data = response.read()
        # print(json.loads(data.decode("utf-8")))
        # print(data.decode("utf-8"))
        conn.close()
        return json.loads(data.decode("utf-8"))
    except Exception as e:
        print("[Errno {0}] {1}".format(e.errno, e.strerror))
        

if __name__ == '__main__':
    ge = facedec("test2.jpeg")
    if len(ge) != 0:
        print(ge[0]['faceAttributes']['emotion'])