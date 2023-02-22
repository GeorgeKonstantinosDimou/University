import javax.swing.*;
import javax.swing.*;

//this class is called upon in case the suspect is not found!
public class ErrorMessage extends JFrame{

	JPanel panel = new JPanel();
	JButton okButton = new JButton();
	
	public ErrorMessage(String name) {
		String message = "Suspect " + name + " Not Found";
		JOptionPane.showMessageDialog(new JFrame(), message);
		
		panel.add(okButton);
		
		okButton = new JButton("OK");
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
}
