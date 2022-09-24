## 請依規格完成能產出以下動態結果的程式：

Please input an integer: 123

All integers have the same digits with 123 are:

321

312

231

213

132

123



規格 ：

1.	請用遞迴的方法，撰寫出能計算出傳入整數共有幾位數字(digits)的函式NoDigits。例如說：輸入123，函式回傳3；輸入1234，函式回傳4。雛型式為：int NoDigits(int x);。

2.	請撰寫一個函式DelDigit，輸入一整數參數及指定其中一個位數，該函式會傳回除掉該位數的整數給呼叫者。例如說：輸入123及指定第2位，函式回傳整數13；輸入1234及指定第4位，函式回傳整數234。雛型式為：int DelDigit(int x, int delD);

3.	利用以上二個函式，及使用遞迴的方法，撰寫出函式TheSameDigits，該函式的輸入參數，需至少有一個目標的整數，其它的部份則開放各位設計。

    HINT:老師設計的範例函式的雛型式為：void TheSameDigits(int x, int overhead = -1);

4.	在主函式main中，提示並要求使用者輸入一個整數，然後呼叫TheSameDigits來進行所有相同數字的所有整數列表。

5.	請不要忘記在檔頭及核心區撰寫註解。

6.	上傳的檔名格式為"H5_學號.cpp"。
