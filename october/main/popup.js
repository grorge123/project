$(function(){
    chrome.storage.sync.get(['name'], function(budget){
        chrome.storage.sync.get('name', function(budget){
            $('#name').text(budget.name);//設定name

            let txt = '';//讀取txt
            let xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function(){
                if (xmlhttp.status == 200 && xmlhttp.readyState == 4){
                        txt = xmlhttp.responseText;
                        document.getElementById("local").innerHTML=txt
                    }
            };
            xmlhttp.open("GET", "data/" + budget.name + ".txt", true);
            xmlhttp.send();
        });
    });
    $('#update').click(function(){
        chrome.storage.sync.get('name', function(budget){
            $('#name').text(budget.name);//設定name

            let txt = '';//讀取txt
            let xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function(){
                if (xmlhttp.status == 200 && xmlhttp.readyState == 4){
                        txt = xmlhttp.responseText;
                        document.getElementById("local").innerHTML=txt
                    }
            };
            xmlhttp.open("GET", "data/" + budget.name + ".txt", true);
            xmlhttp.send();
        });
    });
})