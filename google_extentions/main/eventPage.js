chrome.runtime.onMessage.addListener(function(request, sender, sendResponse){
    if( request.todo == "showPageAction"){
        chrome.tabs.query({active:true, currentWindow: true}, function(tabs){
            chrome.pageAction.show(tabs[0].id)
        });
    }
})


var contextMenuItem = {
    "id": "housename",
    "title": "housename",
    "contexts": ["selection"]
}
chrome.contextMenus.create(contextMenuItem);

chrome.contextMenus.onClicked.addListener(function(clickData){
    if (clickData.menuItemId == "housename" && clickData.selectionText){
        chrome.storage.sync.set({'name':clickData.selectionText})
    }
});