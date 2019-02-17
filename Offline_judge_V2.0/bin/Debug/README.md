此judge有4種模式
請在judge執行程式目錄下放入比賽資料夾,裡面須包含一個index.txt檔案和名稱為inp,judge,score,out,pro,special的資料夾
index.txt第一行為n代表題目數量,接下來有n行,每行分別為type is_strict ans pro time special
tpye 為題目模式分別有 normal hack debug special
is_strict 為是否嚴格比對請放入 0或1
ans 為題目在ans資料夾的答案檔案名稱
pro 為pi,i為第幾題的數字
time 為題目時間限制
special 除了normal模式以外都要輸入代表在special資料夾special judge的名稱(在debug模式下special 為edit number)
並且在輸入完題目後輸入m代表有多少使用者並在接下來m行打上使用者名稱

請將各題目的答案放在judge資料夾並且命名為pi,i為第幾題的數字
請使用者將上傳程式傳入inp資料夾檔名格式為"檔案名稱_pi.cpp"i為第幾題的數字
並且會將使用者的成績輸出在score資料夾裡

normal 為一般的輸入測資測試答案是否正確,因此不需要放東西到ans資料夾,但還是要填名字
hack 為測試使用者輸入的測資是否能使程式執行不正確,程式會將使用者的文件傳入special judge裡面請自行判斷範圍並輸出應該輸出的內容(題目所給的程式碼),並比對輸出內容跟正確答案的差別,而ans資料夾的程式為正確範例的程式,如果使用者輸入不符合範圍的測資請回傳re
debug 將一份錯誤程式碼給使用者debug並傳上正確的,會將debug的程式做一般的normal模式處理但會確認edit number,並且在ans資料夾放入正確原始code
special 直接將使用者的程式輸出給special judge並由special judge 的回傳值來表示結果,因此也不需要放入ans資料,但需要再pro資料夾放空的檔案

0 = "Oh! CE! Maybe you need to see your code again"
1 = "Wow!That is AC!!!You are so smart!"
2 = "TLE! Your program run time is to more";
3 = "WA!!Your program runs result is not same as anser!!!(Be careful!!!Otherwise you will see me again) *\(O_O)/*";
4 = "RE!!Maybe some bug in your code but it can be compile";
5 = "SE!!WTF! Please tell manager the problem";