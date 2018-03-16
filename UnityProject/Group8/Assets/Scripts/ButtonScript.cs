using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ButtonScript : MonoBehaviour {

    public Button replay;
    public Button menu;

	// Use this for initialization
	void Start () {

        gameObject.GetComponent<AudioSource>().Play();
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
