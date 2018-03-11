using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Salmon inherits all of food behavior from the base class 
public class Salmon : Food
{
    // TODO: We could set speed here

    public void OnBecameInvisible()
    {
        level.GetComponent<LevelManager>().DestroySalmon();
    }
}
