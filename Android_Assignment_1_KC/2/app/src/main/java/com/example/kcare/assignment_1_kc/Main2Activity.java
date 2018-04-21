package com.example.kcare.assignment_1_kc;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Main2Activity extends AppCompatActivity implements View.OnClickListener {
    TextView textViewresults;
    Button btnReturn;
    Double sum = 0.0;
    double max,min = 0.0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        btnReturn = (Button) findViewById(R.id.btnBack2Main);
        btnReturn.setOnClickListener(this);
        textViewresults = (TextView) findViewById(R.id.TextViewShowResults) ;
        Intent intent2 = getIntent();
        Bundle b2 = intent2.getExtras();

        Double a1 = b2.getDouble("val1");
        Double a2 = b2.getDouble("val2");
        Double a3 = b2.getDouble("val3");
        Double a4 = b2.getDouble("val4");
        Double a5 = b2.getDouble("val5");
        Double[] maxMinArray = { a1, a2, a3, a4, a5};

        for (int i = 0; i < maxMinArray.length; i++) {
            if(max < maxMinArray[i]){
                max = maxMinArray[i];
            }
        }
        min = maxMinArray[0];
        for (int i = 0; i < maxMinArray.length; i++) {
            if(min > maxMinArray[i]){
                min = maxMinArray[i];
            }
        }

        sum = a1+a2+a3+a4+a5;
        textViewresults.setText("Num1: " +a1 + "\nNum2: " +a2
                + "\nNum3: " +a3 + "\nNum4: " +a4 + "\nNum5: " +a5 +
                "\nmax: " + max + "\nMin: " + min +"\nSum:" + sum );

        b2.putDouble("max" ,max);
        b2.putDouble("min" , min);
        b2.putDouble("sum" , sum);

        intent2.putExtras(b2);

        setResult(Activity.RESULT_OK , intent2);

    }
    @Override
    public void onClick(View v) {
        finish(); //terminate activity 2
    }
}
