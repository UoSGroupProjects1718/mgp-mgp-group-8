using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Nigri inherits all of food behavior from the base class 
public class Nigri : Food
{
    public void OnBecameInvisible()
    {
        level.GetComponent<LevelManager>().DestroyNigri();
    }
}
