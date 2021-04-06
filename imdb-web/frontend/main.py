import json
import requests
import streamlit as st
from PIL import Image

# https://discuss.streamlit.io/t/version-0-64-0-deprecation-warning-for-st-file-uploader-decoding/4465
st.set_option("deprecation.showfileUploaderEncoding", False)

# defines an h1 header
st.title("comment classfication")

# displays a file uploader widget
# image = st.file_uploader("Choose an image")

# displays the select widget for the styles
# style = st.selectbox("Choose the style", [i for i in STYLES.keys()])

text = st.text_area("input your comment")


# displays a button
if st.button("check"):
    if text is not None and len(text) < 256:
        datas = {"text":text}
        res = requests.post(f"http://backend:8080/check", data=json.dumps(datas))
        if int(res.text):
            st.text("This is a postive comment")
        else:
            st.text("This is a negtive comment")
    else:
        st.text("Your input is invalid")