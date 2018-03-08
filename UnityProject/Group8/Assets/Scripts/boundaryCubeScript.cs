using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoundaryCubeScript : MonoBehaviour
{
    // TODO: We could replace this with a get object pool method
    public GameObject currentPrawn;
    public GameObject currentDumpling;
    public GameObject currentSalmon;
    public GameObject currentNigri;

    // Event called on begin overlap with trigger box
    private void OnTriggerEnter(Collider other)
    {
       if (other.gameObject.tag == "Prawn")
       {
            currentPrawn = other.gameObject;
       }
       if (other.gameObject.tag == "Dumpling")
       {
            currentDumpling = other.gameObject;
       }
       if (other.gameObject.tag == "Salmon")
       {
           currentSalmon = other.gameObject;
       }
       if (other.gameObject.tag == "Nigri")
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
			currentDumpling = null;
		}
        if (other.gameObject.tag == "Salmon")
        {
            currentSalmon = other.gameObject;
        }
        if (other.gameObject.tag == "Nigri")
        {
            currentNigri = other.gameObject;
        }
    }
}
