package com.dqfx.ppldz;



import android.app.Activity;
import android.app.ListActivity;
import android.app.ProgressDialog;
import android.content.Context;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Message;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.*;
import android.widget.AdapterView.OnItemClickListener;

import java.io.File;
import java.io.IOException;
import java.nio.CharBuffer;
import java.util.HashMap;

import mm.purchasesdk.OnPurchaseListener;
import mm.purchasesdk.Purchase;
import mm.purchasesdk.PurchaseCode;

import org.cocos2dx.cpp.AppActivity;
import org.cocos2dx.lib.Cocos2dxActivity;




public class MainActivity extends Cocos2dxActivity {

  static final String[] BUTTONS = new String[]{
	  "",
	  "新手礼包",
	  "1元钻石礼包",
	  "4元钻石礼包",
	  "6元钻石礼包",
	  "8元钻石礼包",
	  "10元钻石礼包",
	  "15元钻石礼包",
	  "18元钻石礼包",
	  "29元钻石礼包",
	  "钻石大礼包",
	  "泡泡大礼包",
  };
  
  
  private static String getPayIdBuyIndex(int index){
	  String str;
	  if(index < 10){
		  
		 str = "3000089924510" + index;
	  }
	  else{
		  str = "300008992451" + index;
	  }
	  
	  return str;
  }
  
  private static int getIndexByPayId(String payId){
	  long i = Long.parseLong(payId);
	  Log.w("calljava","--------------------Long--------------" + i);
	  int j = (int) (i % 100);
	  //Log.w("calljava","--------------------int--------------" + (i % 100));
	  return j;
  }
  
  
  
  
  

	private static final String APPID = "300008992451";
	private static final String APPKEY = "2309150DB45A73B97ABA0DCB8F01942B";
	public static Purchase purchase;
	public static IAPListener listener;
	static Context mContext;
	
  
	   public native static void payOK(int index);
	   public native static void payFailed();
	   public native static void endGame();
	
	public class IAPListener implements OnPurchaseListener{

	@Override
	public void onAfterApply() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onAfterDownload() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onBeforeApply() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onBeforeDownload() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onBillingFinish(int arg0, HashMap arg1) {
		
		Log.w("calljava","--------------------Billing--------------");
		String payCode = (String) arg1.get(OnPurchaseListener.PAYCODE);
		//getIndexByPayId(payCode);
		Log.w("calljava","--------------------Billing--------------" + payCode);
		Log.w("calljava", "-------" + getIndexByPayId(payCode) + "---------");
		int index = getIndexByPayId(payCode);
		// TODO Auto-generated method stub
		//String result;
		if (arg0 == PurchaseCode.ORDER_OK || (arg0 == PurchaseCode.AUTH_OK) ||(arg0 == PurchaseCode.WEAK_ORDER_OK)) {
			/**
			 * BILL_SUCCEED,表示订购成功 AUTH_SUCCEED，表示该商品已经订购。
			 */
			Log.w("calljava","--------------------payOk--------------" );
			payOK(index);
		} else {
			/**
			 * 表示订购失败。
			 */
			payFailed();
			Log.w("calljava","--------------------payFailed--------------" + index);

		}
		
	}

	@Override
	public void onInitFinish(int arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onQueryFinish(int arg0, HashMap arg1) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onUnsubscribeFinish(int arg0) {
		// TODO Auto-generated method stub
		
	}}
  
  
  
  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    mContext = this;
    Log.w("calljava","--------------------init()--------------");
    purchase = Purchase.getInstance();
    
	try {
		purchase.setAppInfo(APPID, APPKEY);
	} catch (Exception e1) {
		e1.printStackTrace();
	}
	
	listener = new IAPListener();
	purchase.init(mContext, listener);
    //IsMusicOn();
   
  }
  
  public static void payGold(int index){
	  Log.w("calljava","--------------------pay--------------");
	  //payFailed();
	  purchase.order(mContext, getPayIdBuyIndex(index), listener);
  }

  public static void exitGame() {
	  
	  
}
  

}

