$(function(){
    chrome.storage.sync.get('limit',function(budget){
        $('#limit').val(budget.limit);
    });
    $('#saveLimit').click(function(){
        var limit = $("#limit").val();
        if(limit){
            chrome.storage.sync.set({'limit': limit});
        }
    });
    $('#reserTotal').click(function(){
        chrome.storage.sync.set({'total':0}, function(){
            var notifiOptions = {
                type: 'basic',
                iconUrl: 'icon48.png',
                title: 'Limit reached!',
                message: 'total reset to 0'
            };
            chrome.notifications.create('limitNotif', notifiOptions);
        });
    });    
});