import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*
import android.net.wifi.WifiConfiguration
import android.net.wifi.WifiManager

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val wifiManager = applicationContext.getSystemService(WIFI_SERVICE) as WifiManager
        val wifiList = wifiManager.configuredNetworks

        val wifiInfo = StringBuilder()
        for (wifi in wifiList) {
            wifiInfo.append("SSID: ${wifi.SSID}, Password: ${wifi.preSharedKey}\n")
        }

        wifiTextView.text = wifiInfo.toString()
    }
}
