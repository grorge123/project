$(function(){
    chrome.storage.sync.get(['name'], function(budget){
        chrome.storage.sync.get('name', function(budget){
            $('#name').text(budget.name);//設定name

            let txt = '';//讀取txt
            let xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function(){
                if (xmlhttp.status == 200 && xmlhttp.readyState == 4){
                        txt = xmlhttp.responseText;
                        head = "<div id=\"houseinfo\"><span style=\"font-family:Microsoft JhengHei;;\"><p align=\"center\"><front size=\"5\">租房提醒小幫手</front><br></p></span><span style=\"font-family:Microsoft JhengHei;\"><p align=\"left\">"
                        tail = "</p></span></div><style type=\"text/css\"> #houseinfo{border:5px solid 	#BCD2EE;border-radius:45px;width:700px;height:300px;background-color:	#CAE1FF;}</style>"
                        document.getElementById("local").innerHTML=head+txt+tail
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
                        head = "<div id=\"houseinfo\"><span style=\"font-family:Microsoft JhengHei;;\"><p align=\"center\"><front size=\"5\">租房提醒小幫手</front><br></p></span><span style=\"font-family:Microsoft JhengHei;\"><p align=\"left\">"
                        tail = "</p></span></div><style type=\"text/css\"> #houseinfo{border:5px solid 	#BCD2EE;border-radius:45px;width:700px;height:300px;background-color:	#CAE1FF;}</style>"
                        document.getElementById("local").innerHTML=head+txt+tail
                }
            };
            xmlhttp.open("GET", "data/" + budget.name + ".txt", true);
            xmlhttp.send();
        });
    });
})