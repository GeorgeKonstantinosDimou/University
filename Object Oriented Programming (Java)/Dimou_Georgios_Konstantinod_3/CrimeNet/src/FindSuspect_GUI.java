import java.util.ArrayList;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.awt.*;

public class FindSuspect_GUI extends JFrame {
	
	private JPanel panel = new JPanel();
	private JButton findSuspect;
	private JTextField suspectsname;
	
	private ArrayList<Suspect> susp;
	private Registry aReg;
	
	public FindSuspect_GUI(ArrayList<Suspect> suspects) {
		
		susp = suspects;
		
		suspectsname = new JTextField("Please enter the suspect's name");
		findSuspect = new JButton("Find");
		
		panel.add(suspectsname);
		panel.add(findSuspect);
		
		this.setContentPane(panel);
		
		this.setSize(300, 150);
		this.setVisible(true);
		this.setTitle("Find Suspect");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		ButtonListener listener = new ButtonListener();
		findSuspect.addActionListener(listener);;
		
	}
	
	
	  class ButtonListener implements ActionListener{
	 
		  //private SuspectsPage_GUI suspage = new SuspectsPage_GUI(Suspect);
		  
	  public void actionPerformed(ActionEvent e) {
		  
		  boolean flag = false;
		  String susName = suspectsname.getText();
		  
		  for(Suspect sus: susp) {
			  if(sus.getName().equals(susName)) {
				  SuspectsPage_GUI susInfo = new SuspectsPage_GUI(sus, aReg, susp);
				  flag = true;
				  break;
		  }
	  	 }
		  //if flag equals false this means that the Suspect was not found, so print out a corresponding message 
		  if(!flag) {
			 ErrorMessage err = new ErrorMessage(susName);
		  }
	    }
	   }
}