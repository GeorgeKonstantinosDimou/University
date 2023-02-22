import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class SuspectsPage_GUI extends JFrame {

	JPanel panel = new JPanel();
	JPanel fieldPanel = new JPanel();
	
	JTextField susName, susCodeName, telList, aTelephoneNumber, sms, partners, suggestedPartners;
	JButton findSms, returntoSearchScreen;
	
	private Suspect asus;
	private Registry areg;
	private ArrayList<Suspect> allsuspects;
	
	public SuspectsPage_GUI(Suspect aSuspect, Registry aRegistry, ArrayList<Suspect> suspects) {
		
		asus = aSuspect;
		areg = aRegistry;
		allsuspects = suspects;
		
		panel.setLayout(new BorderLayout());
		fieldPanel.setLayout(new GridLayout(3, 4, 10, 300));
		
		
		susName = new JTextField(aSuspect.name);
		susCodeName = new JTextField(aSuspect.codeName);
		//telList = new JTextField(aSuspect.getTelNumbers());
		aTelephoneNumber = new JTextField("Insert telephone to search");
		partners = new JTextField();
		suggestedPartners = new JTextField();
		findSms = new JButton("Find SMS");
		returntoSearchScreen = new JButton("Back to Search Screen");
		
		
		
		fieldPanel.add(susName);
		fieldPanel.add(susCodeName);
		//fieldPanel.add(telList);
		fieldPanel.add(aTelephoneNumber);
		fieldPanel.add(partners);
		fieldPanel.add(suggestedPartners);
		fieldPanel.add(findSms);
		fieldPanel.add(returntoSearchScreen);
		
		panel.add(fieldPanel, BorderLayout.NORTH);
		//panel.add()
		
		this.setContentPane(panel);
		this.setVisible(true);
		this.setSize(500,800);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		ButtonListener listener1 = new ButtonListener();
		findSms.addActionListener(listener1);
		
		ButtonListener2 listener2 = new ButtonListener2();
		returntoSearchScreen.addActionListener(listener2);
	}
		
		class ButtonListener implements ActionListener{
			
			public void actionPerformed(ActionEvent e) {
				
				String numb = aTelephoneNumber.getText();
				ArrayList<SMS> alistofMessages = areg.getMessagesBetween(numb, asus.getTelNumbers().get(0) );
				for(SMS sms: alistofMessages)
					System.out.println(sms);
			}
		}	
		
		class ButtonListener2 implements ActionListener{
			
			public void actionPerformed(ActionEvent e) {
				
				FindSuspect_GUI findsus_Gui = new FindSuspect_GUI(allsuspects);
			}
		}
		
	
}
