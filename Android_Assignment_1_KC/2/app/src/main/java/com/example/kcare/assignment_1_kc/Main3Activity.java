package com.example.kcare.assignment_1_kc;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Main3Activity extends AppCompatActivity implements View.OnClickListener {
    Button btnReturn;
    TextView AveTextView;
    Double Average = 0.0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        btnReturn = (Button) findViewById(R.id.ButtonReturn);
        btnReturn.setOnClickListener(this);
        AveTextView = (TextView) findViewById(R.id.AverageTV);

        Intent intent5 = getIntent();
        Bundle b5 = intent5.getExtras();

        double[] AverageArray = b5.getDoubleArray("NumArray");

        for (int i = 0; i < AverageArray.length; i++) {

            Average = Average + AverageArray[i];
        }
        double Val1 = AverageArray[0];
        double Val2 = AverageArray[1];
        double Val3 = AverageArray[2];
        double Val4 = AverageArray[3];
        double Val5 = AverageArray[4];
        Average = Average / AverageArray.length;
        AveTextView.setText("Value one: " + Val1 + "\n Value two: " + Val2
                + "\n Value three: " + Val3 + "\n Value four: " + Val4
                + "\n Value five: " + Val5
                + "\nAverage of the " + AverageArray.length + ":  " + Average);

        b5.putDouble("AveArray", Average);
        intent5.putExtras(b5);
        setResult(Activity.RESULT_OK, intent5);
    }
    @Override
    public void onClick(View v) {
        finish(); //terminate activity 3
    }
}
