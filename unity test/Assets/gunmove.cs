using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class gunmove : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject Obj;
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
        gameObject.transform.rotation =  Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan);
        if (Input.GetKeyDown(KeyCode.Space))
        {
            print("fire");
            Instantiate(Bullet, gameObject.transform.position, Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan + 90));
        }
    }
}
