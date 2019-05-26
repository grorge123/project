using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class gunmove : MonoBehaviour
{
    // Start is called before the first frame update
    //public GameObject Obj;
    public GameObject Bullet;
    void Start()
    {
        
    }
    // Update is called once per frame
    void Update()
    {
        Vector3 people_position = control.people_position;
        people_position += new Vector3(1, 0.3f, 0);
        gameObject.transform.position = people_position;
        const float PI = 3.14159265359F;
        float tan = (gameObject.transform.position.y - Input.mousePosition.y) / (gameObject.transform.position.x - Input.mousePosition.x);
        tan = Mathf.Atan(tan) * 180 / PI;
        //gameObject.transform.rotation =  Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan);
        float angleZ = Mathf.Atan2(Input.mousePosition.y, Input.mousePosition.x) * Mathf.Rad2Deg;
        gameObject.transform.eulerAngles = new Vector3(0, 0, angleZ);
        Vector2 mpos = RectTransformUtility.WorldToScreenPoint(Camera.main, Input.mousePosition);
        if (Input.GetKeyDown(KeyCode.Space))
        {
            print("fire");
            Vector3 pos = gameObject.transform.position;
            pos.x += 2;
            print(string.Format("{0} {1}", mpos.x, mpos.y));
            Instantiate(Bullet, pos, Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan ));
        }
    }
}
