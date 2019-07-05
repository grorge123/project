using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
namespace tool
{
    static class tool
    {
        public static System.Random rnd = new System.Random(Guid.NewGuid().GetHashCode());
        public static float PI()
        {
            return 3.14159265359F;
        }
        public static float DirectionToRotation(Vector3 direction)
        {
            float tan = (direction.y / direction.x);
            tan = Mathf.Atan(tan) * 180 / tool.PI();
            return tan;
        }
        public static Vector3 Normalize(Vector3 a)
        {
            float sq = (float)System.Math.Sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
            a.x /= sq;
            a.y /= sq;
            return a;
        }
        public static Vector3 TwoUnitvector3(Vector3 a, Vector3 b)
        {
            Vector3 director = b - a;
            director.z = 0;
            director.Normalize();
            return director;
        }
        public static Vector3 get_mouse()
        {
            Camera camera = Camera.main;
            Vector3 mpos = camera.ScreenToWorldPoint(Input.mousePosition);
            return mpos;
        }
        public static Vector3 Mousedirector(Vector3 now)
        {
            Vector3 re = get_mouse() - now;
            return re;
        }
        
    }
}
