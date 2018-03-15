using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boundaryCubeScript : MonoBehaviour {

    public GameObject currentPrawn;
    public GameObject currentDumpling;


    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Prawn")
        {
            currentPrawn = other.gameObject;
        }
       if(other.gameObject.tag == "Dumpling")
        {
            currentPrawn = other.gameObject;
        }
       if(other.gameObject.tag == "Maki")
        {
            currentPrawn = other.gameObject;
        }
    }


    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Prawn")
        {
            currentPrawn = null;
        }

		if (other.gameObject.tag == "Dumpling")
        {
			currentPrawn = null;
		}

        if (other.gameObject.tag == "Maki")
        {
            currentPrawn = null;
        }
    }
}
