package org.ylgame.com;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;


public class BatteryBroadcastReceiver extends BroadcastReceiver{
	//������ֵ
    
    public static int batteryLevel = 0;
	
	//��ȡ������Ϣ
	public static int getBatteryLevel() {
	    return batteryLevel;
	} 
    @Override
    public void onReceive(Context context, Intent intent) {
        // TODO Auto-generated method stub
        //�ж����Ƿ���Ϊ�����仯��Broadcast Action
        if(Intent.ACTION_BATTERY_CHANGED.equals(intent.getAction())){
            //��ȡ��ǰ����
            int level = intent.getIntExtra("level", 0);
            //�������̶ܿ�
            int scale = intent.getIntExtra("scale", 100);
            //����ת�ɰٷֱ�
            batteryLevel =  level * 100 / scale;
        }
    }

   
};

