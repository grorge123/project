$(function(){
    chrome.storage.sync.get(['name'], function(budget){
        $('#name').text(budget.name)
    });
    $('#update').click(function(){
        chrome.storage.sync.get('name', function(budget){
            $('#name').text(budget.name);
        });
    });
})