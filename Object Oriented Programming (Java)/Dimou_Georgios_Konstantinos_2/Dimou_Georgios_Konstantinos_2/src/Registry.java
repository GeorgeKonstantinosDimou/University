import java.util.ArrayList;

public class Registry {

	//an ArrayList of type Suspect containing all the CrimeNet Suspects 
	private ArrayList<Suspect> aSus= new ArrayList<Suspect>();
	//an ArrayList of type Communication containing all the Communications made in the CrimeNet 
	private ArrayList<Communication> aCom = new ArrayList<Communication>();
	//an ArrayList which contains all the partners
	private ArrayList<Suspect> partners = new ArrayList<Suspect>();
	
	//method of adding Suspects in the list 
	public void addSuspect(Suspect aSuspect) {
		aSus.add(aSuspect);
	}
	
	//method of adding the Communications in the list
	//also if the Communication Type is a phone call 
	//it adds the 2 numbers in the Partners List 
	public void addCommunication(Communication aCommunication) {
		int i=0;
		int j=0;
		
		aCom.add(aCommunication);
		//typeofCommuniacation == 0 if and only if the comm is of type PhoneCall 
		if(aCommunication.typeofCommunication == 0) {
			for(Suspect suspect: aSus) {
				//the following code line checks if suspect contains a given number(from the Communications) in his list 
				if(suspect.containsTelNumber(suspect.getTelNumbers(), aCommunication.Num1)) {
					for(Suspect suspect2: aSus) {
						//if both of the if are true then suspect/suspect2 are partners, put them on each others partners list!
						if(suspect2.containsTelNumber(suspect2.getTelNumbers(), aCommunication.Num2)) {
							partners.add(i, suspect2);
							partners.add(j, suspect);
							j++;
					}
				}
			}
				i++;
		}
	}
}
	//method which returns the suspect with the most partners
	public Suspect getSuspectWithMostPartners() {
		int max = 0 ;
		int i = 0;
		int potition = 0;
		
		for(Suspect suspect: aSus) {
			if(suspect.numberOfPartners(suspect) > max)
				max = suspect.numberOfPartners(suspect);
				potition = i;
		}
		i++;
		return aSus.get(potition);
}
	
	//a method which returns the longest duration phone call between 2 given suspects numbers
	//its complexity is bad but i didnt have anymore time to fix it properly...
	public PhoneCall getLongestPhoneCallBetween(String number1, String number2) {
		int max = 0;
		int i = 0;
		int potition = 0;
		ArrayList<PhoneCall> Coms = new ArrayList<PhoneCall>();
		
		for(Communication communication: aCom) {
			//checks if is a phone call 
			if(communication.typeofCommunication == 0) {
				for(Suspect suspect: aSus) {
					//the following code line checks if suspect contains a given number in his list 
					if(suspect.containsTelNumber(suspect.getTelNumbers(), number1)) {
						for(Suspect suspect2: aSus) {
							if(suspect2.containsTelNumber(suspect2.getTelNumbers(), number2)) {
									Coms.add((PhoneCall) communication);
								}
						}
					}
				}
			}
		}
		//Compare every Phone Call duration with a max and return the max Com
		for(PhoneCall Pcall: Coms) {
			if(Pcall.getCallDuration() > max) {
				max = Pcall.getCallDuration();
				potition = i;
			}
			i++;
		}
		return Coms.get(i);
	}
	
	public ArrayList<SMS> getMessagesBetween(String number1, String number2) {
		
		ArrayList<SMS> Coms1 = new ArrayList<SMS>();
		
		for(Communication communication: aCom) {
			//checks if is a phone call 
			if(communication.typeofCommunication == 1) {
				for(Suspect suspect: aSus) {
					//the following code line checks if suspect contains a given number in his list 
					if(suspect.containsTelNumber(suspect.getTelNumbers(), number1)) {
						for(Suspect suspect2: aSus) {
							if(suspect2.containsTelNumber(suspect2.getTelNumbers(), number2)) {
									Coms1.add((SMS) communication);
								}
						}
					}
				}
			}
		}
		//if those specific words occur inside those messages return the communication SMS 
		for(SMS sms: Coms1) {
			if(!(sms.getMessage().contains("Bomb") && sms.getMessage().contains("Attack") && sms.getMessage().contains("Explosives") && sms.getMessage().contains("Gun"))) {
				Coms1.remove(sms);
			}
				
		}
		return Coms1;
	}
	
}

	
