using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LsideF : MonoBehaviour
{
    // Start is called before the first frame update
	public GameObject t;
	void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void OnTriggerEnter2D(Collider2D col)
    {
		if(col.tag == "Bullet")
            
            Destroy(col.gameObject);
    }
}
