using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Threading;

namespace tool
{
    static class too
    {
        public static System.Random rnd = new System.Random(Guid.NewGuid().GetHashCode());

        public static int calloutfile(string path)
        {
            double w1 = rnd.Next(0,10) + rnd.NextDouble();
            double w2 = rnd.Next(0, 10) + rnd.NextDouble();
            double w3 = rnd.Next(0, 10) + rnd.NextDouble();
            double[] ansy = new double[500];
            double[] ansx = new double[500];
            for (int i = 0; i < 200; i++)
            {
                ansx[i] = rnd.NextDouble();
                ansy[i] = w1 * ansx[i] * ansx[i] + w2 * ansx[i] + w3;
            }
            double[] iny = new double[105];
            using (StreamWriter sw = new StreamWriter(path + "input"))
            {
                for (int i = 0; i < 100; i++)
                {
                    sw.WriteLine(ansx[i]);
                    sw.WriteLine(' ');
                    sw.WriteLine(ansy[i]);
                }
            }
            System.Diagnostics.Process p = new System.Diagnostics.Process();
            p.StartInfo.FileName = "cmd.exe";
            p.StartInfo.Arguments = @"python " + path + "use.py" + " < " + path + "input > " + path + "ouput";
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.RedirectStandardInput = true;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.RedirectStandardError = true;
            p.StartInfo.CreateNoWindow = true;
            p.Start();
            using (StreamReader sw = new StreamReader(path + "output"))
            {
                for (int i = 0; i < 100; i++)
                {
                    iny[i] = double.Parse(sw.ReadLine());
                }

            }
            double loss = 0;
            for(int i = 0; i < 100; i++)
            {
                loss += (ansy[i] - iny[i]) * (ansy[i] - iny[i]);
            }
            loss = Math.Sqrt(loss);
            loss /= 100;
            for(int i = 5,k = 2; i > 1; i--,k++)
            {
                if(loss <= k)
                {
                    return i;
                }
            }
            return 0;
        }
    }
}
