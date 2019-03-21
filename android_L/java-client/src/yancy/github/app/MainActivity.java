package yancy.github.app;


import android.app.Activity;
import android.util.Log;
import android.os.ServiceManager;
import android.os.Binder;
import yancy.github.nativeservice.IDemoService;
import android.os.IBinder;
import android.os.Bundle;
import android.os.RemoteException;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        try {
            IBinder b = ServiceManager.getService("yancy.github.nativeservice");
            if(b != null) {
                final IDemoService service =
                        IDemoService.Stub.asInterface(b);
                if(service != null) {
                    Log.d("DEMOSERVICE", "AddNumber(23, 24): " + service.AddNumber(23, 24));
                    Log.d("DEMOSERVICE", "MaxNumber(23, 24): " + service.MaxNumber(23, 24));
                    Log.d("DEMOSERVICE", "MaxNumber(33, 24): " + service.MaxNumber(33, 24));
                } else {
                    Log.d("DEMOSERVICE", "MainActivity asInterface fail.");
                }
            } else {
                Log.d("DEMOSERVICE", "MainActivity get native service fail.");
            }
        } catch(RemoteException e) {
            Log.d("DEMOSERVICE", "ERROR:" + e.getMessage());
        }
    }
}
