using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boundaryCubeScript : MonoBehaviour
{
    // TODO: We could replace this with a get object pool method
    public GameObject currentPrawn;
    public GameObject currentDumpling;
    public GameObject currentSalmon;
    public GameObject currentNigri;

    private Dumpling dumpling;

    // Event called on begin overlap with trigger box
    private void OnTriggerEnter(Collider other)
    {
       if (other.gameObject.tag == "Prawn")
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

       if(other.gameObject.tag == "Squid")
       {
            currentNigri = other.gameObject;
       }
    }

    // Event called on end overlap with trigger box
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

        if(other.gameObject.tag == "Squid")
        {
            currentNigri = null;
        }
    }
}
