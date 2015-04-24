package com.dqfx.ppldz;

import android.app.Application;

public class CmgameApplication extends Application {
	  public void onCreate() {
	    try {
	System.loadLibrary("megjb");
	} catch(Exception e){}
	  }
}
