chrome.runtime.sendMessage({todo: "showPageAction"});
$(function(){
    var name = $('.addr').text();
    chrome.storage.sync.set({'name': name});
});
