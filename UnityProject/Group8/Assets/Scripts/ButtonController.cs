using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonController : MonoBehaviour
{
    public GameObject animObject;

    public void PlayAnim()
    {
        animObject.GetComponent<Animator>().SetTrigger("Explode");
    }
}
