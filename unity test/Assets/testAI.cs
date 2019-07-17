using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Threading;

public class testAI : MonoBehaviour
{
    // Start is called before the first frame update
    string path;
    public static bool seccess = false;
    int[] co = new int[5];
    void Start()
    {
        string path = System.Environment.CurrentDirectory;
        try
        {
            //指定委派物件
            ThreadStart MissionA_Tg = new ThreadStart(use_try);
            //建立A任務執行緒
            Thread MissionA_Thread = new Thread(MissionA_Tg);
            MissionA_Thread.Start();
            Thread.Sleep(1000);
            MissionA_Thread.Abort();
            
        }
        finally
        {
            seccess = true;
        }
    }


    // Update is called once per frame
    void Update()
    {
        
    }
    private void use_try()
    {
        for (int i = 0; i < 5; i++)
        {
            print(co[i]);
            co[i] = tool.too.calloutfile(path);
            print(co[i]);
        }
        return;
    }
}
