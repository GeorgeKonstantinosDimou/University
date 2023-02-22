import java.io.File;
import java.io.IOException;
import java.awt.Color;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class SetPixelsSimpleParallel {

	static final int numofThreads = 4;
	
	public static void main(String[] args) {

		//Reading the image
		String fileNameR = "../SimpleParallel_Lab2/original.jpg";
		String fileNameW = "../SimpleParallel_Lab2/new.jpg";
				
		BufferedImage img = null;
		try {
		    img = ImageIO.read(new File(fileNameR));
		} catch (IOException e) {}
		

		long start = System.currentTimeMillis(); 
		
		//Creation of a shared object
		sharedColorShiftsVariables colorShift = new sharedColorShiftsVariables();
		
		pixelThread[] threads = new pixelThread[numofThreads];
		for(int i=0;i<numofThreads;i++) {
			threads[i] = new pixelThread(i, img, colorShift);
			threads[i].start();
		}
		
		
		//Saving the modified image
		File file = new File(fileNameW);
		for(int i=0;i<numofThreads;i++) {
			try {
			threads[i].join();
			ImageIO.write(threads[i].img, "jpg", file);
			} catch (InterruptedException e) {} 
			catch (IOException e) {}
		}
		

		
			
		long elapsedTimeMillis = System.currentTimeMillis()-start;
		       
		      
		
		System.out.println("Done...");
		System.out.println("time in ms = "+ elapsedTimeMillis);
	}
	
	
	static class sharedColorShiftsVariables {
		
		//Create a shared object so i don't need to provide each thread with 
		//3 separate shift variables 
		
		static int redShift;
		static int greenShift;
		static int blueShift;
		
		
		public sharedColorShiftsVariables() {
			this.redShift = 100;
			this.greenShift = 100;
			this.blueShift = 100;
		}	
	}
	
	static class pixelThread extends Thread {
		
		int start;
		int stop;
		int block;
		BufferedImage img;
		//String outputFile;
		int redShift;
		int greenShift;
		int blueShift;
		sharedColorShiftsVariables cShifts;
		
		public pixelThread(int block, BufferedImage image, sharedColorShiftsVariables shifts) {
			this.img = image;
			start = block * (img.getHeight()/numofThreads);
			stop = start + (img.getHeight()/numofThreads);
			if(block == numofThreads-1) stop = img.getHeight();
			this.redShift = cShifts.redShift;
			this.blueShift = cShifts.blueShift;
			this.greenShift = cShifts.greenShift;
			//this.outputFile = newFile;
			
		}
		
		public void run() {
			
			for (int y = start; y < stop; y++) {
				for (int x = 0; x < img.getWidth(); x++) {
					//Retrieving contents of a pixel
					int pixel = img.getRGB(x,y);
					//Creating a Color object from pixel value
					Color color = new Color(pixel, true);
					//Retrieving the R G B values, 8 bits per r,g,b
					int red = color.getRed();
					int green = color.getGreen();
					int blue = color.getBlue();
					//Modifying the RGB values
					red = (red + redShift)%256;
					green = (green + greenShift)%256;
					blue = (blue + blueShift)%256;
					//Creating new Color object
					color = new Color(red, green, blue);
					//Setting new Color object to the image
					img.setRGB(x, y, color.getRGB());
						}
				}
				
		}
		
	}
}
