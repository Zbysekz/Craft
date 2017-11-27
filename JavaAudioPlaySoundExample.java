//https://alvinalexander.com/java/java-audio-example-java-au-play-sound

import java.io.*;
import sun.audio.*;

/**
 * A simple Java sound file example (i.e., Java code to play a sound file).
 * AudioStream and AudioPlayer code comes from a javaworld.com example.
 * @author alvin alexander, devdaily.com.
 */
//Modified by ZW

public class JavaAudioPlaySoundExample
{
  public static void main(String[] args) {
      String programName = "JavaAudioPlaySoundExample"; //this program name
      
      // System.out.println("args.length is " + args.length); // for debugging
      if (args.length != 1) {
	  System.out.println(programName
			     + ": Too few or many command line arguments. ");
	  //args[0] is the name of the program in C but not Java
	  //args[1] is the input to this program in C but not Java
	  //args[0] is the input in Java
      } else {
	  // open the sound file as a Java input stream
	  String audioFile = args[0];
	  //For example, "./sound_effects/shovel_bubblewrap.aiff";
	  
	  try {
	      InputStream in = new FileInputStream(audioFile);
	  
	      // create an audiostream from the inputstream
	      AudioStream audioStream = new AudioStream(in);
	  
	      // play the audio clip with the audioplayer class
	      AudioPlayer.player.start(audioStream);
	  } catch (FileNotFoundException e) {
	      System.err.println(programName
				 + "FileNotFoundException: " + e.getMessage());
	      //will also print to standard output by default
	      //https://duckduckgo.com/?q=what+is+system.err.println&t=canonical&ia=qa
	  } catch (IOException e) {
	      System.err.println(programName
				 + "IOException: " + e.getMessage());
	  }	      
	  //https://docs.oracle.com/javase/tutorial/essential/exceptions/catch.html
      }
  }
}
