package com.example.gil.threads;

import android.content.Context;
import android.os.AsyncTask;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;
import android.os.Handler;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.logging.LogRecord;


/**
 * Saves, loads and clears 
 * @author David Lambertson
 */
public class MainActivity extends ActionBarActivity {

         //public ListView listView = (ListView) findViewById(R.id.listView);

    /**
     *
     * @param savedInstanceState
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    /**
     *
     * @param menu
     * @return
     */
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    /**
     *
     * @param item
     * @return
     */
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    /**
     * @author David Lambertson
     * allows for saving in the background
     */
     class Saving extends AsyncTask<String, String, String> {

         private ProgressBar mProgress;
         private int mProgressStatus = 0;
         private int s = 15;

        /**
         *
         */
        @Override
        protected void onPreExecute() {
            mProgress = (ProgressBar) findViewById(R.id.bar);
            mProgress.setMax(s);
        }

        /**
         *
         * @param url
         * @return
         */
         @Override
         protected String doInBackground(String... url) {
             final String filename = "file.txt";
             //final String string = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n";

             FileOutputStream out;
             try {
                 out = openFileOutput(filename, Context.MODE_PRIVATE);

                 for (Integer i = 0; i <= s; i++) {
                     String x = i.toString();
                     x += "\n";
                     out.write(x.getBytes());

                     publishProgress();
                     Thread.sleep(250);
                 }
                 out.write("cookie".getBytes());
                 out.close();
             } catch (Exception ex) {
                 System.out.println(ex);
             }
             return "hi";
         }

        /**
         *
         * @param progress
         */
         @Override
         protected void onProgressUpdate(String... progress) {
            mProgress.setProgress(mProgressStatus);
             mProgressStatus += 1;
         }

        /**
         *
         * @param file
         */
         @Override
         protected void onPostExecute(String file) {
             Toast.makeText(getApplicationContext(), "File Saved", Toast.LENGTH_SHORT).show();
         }
     }

    /**
     *allows for loading in the background
     */
    public class Loading extends AsyncTask<String, String, String> {
       public ListView listView = (ListView) findViewById(R.id.listView);
       public ArrayAdapter<String> arrayAdapter;

        private ProgressBar mProgress;
        private int mProgressStatus = 0;
        private int s = 15;

        /**
         *
         */
        @Override
        protected void onPreExecute() {
            mProgress = (ProgressBar) findViewById(R.id.bar);
            mProgress.setMax(s);
        }


        /**
         * Loads the file into the list
         * @param url
         * @return
         */
        @Override
        protected String doInBackground(String... url) {

            final String filename = "file.txt";

            try {
                FileInputStream input = openFileInput(filename);

                InputStreamReader reader = new InputStreamReader(input);

                BufferedReader reader1 = new BufferedReader(reader);

                String text;

                ArrayList<String> list = new ArrayList<>();

                while ((text = reader1.readLine()) != null) {
                    Thread.sleep(250);
                    publishProgress();
                    list.add(text);
                }

                arrayAdapter = new ArrayAdapter<>(MainActivity.this, android.R.layout.simple_list_item_1,list);

            }
            catch (Exception ex) {
                ex.printStackTrace();

            }
            return "hi";
        }

        /**
         * updates progress bar
         * @param progress
         */
        @Override
        protected void onProgressUpdate(String... progress) {
            mProgress.setProgress(mProgressStatus);
            mProgressStatus += 1;
        }

        /**
         *
         * @param file
         */
        @Override
        public void onPostExecute(String file) {
            listView.setAdapter(arrayAdapter);
        }
    }

    /**
     * Saves numbers into file when button is clicked
     * @param view
     */
     public void createFile(View view) {
         new Saving().execute();
     }


    /**
     * Loads the file into the list when button is clicked
     * @param view
     */
        public void loadFile(View view){
           new Loading().execute();
        }

    /**
     * Clears the list when button is clicked
     * @param view
     */
        public void clear(View view) {
             ListView listView = (ListView) findViewById(R.id.listView);
             listView.setAdapter(null);
            ProgressBar p = (ProgressBar) findViewById(R.id.bar);
            p.setProgress(0);


        }

    }

