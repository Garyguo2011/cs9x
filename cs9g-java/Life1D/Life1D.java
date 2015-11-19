public class Life1D{

	private Rule rule;
	private int stepCount;

	public static void main (String [ ] args) {
		Life1D simulation = new Life1D ( );
		simulation.processArgs (args);
		//simulation.printRuleLawArray();
		simulation.producePBM ( );
	}
	
	// Print, in Portable Bitmap format, the image corresponding to the rule and step count
	// specified on the command line.
	
	public void producePBM () {
		int[][] pbmGraph = new int [2*stepCount + 1][stepCount + 1];
		int i,j;
		i = 2*stepCount + 1;
		j = stepCount + 1;

		System.out.println("P1 " + i + " " + j);

		for(i = 0; i < 2 * stepCount + 1; i++)
			pbmGraph[i][0] = 0;
		pbmGraph[stepCount][0] = 1;

		 for(j = 1; j < stepCount + 1; j++){
		 	for(i = 0; i < 2 * stepCount + 1; i++){
		 		if (i == 0)
		 			pbmGraph[i][j] = rule.output(0, pbmGraph[i][j-1], pbmGraph[i+1][j-1]);
		 		else if (i == 2 * stepCount) 
		 			pbmGraph[i][j] = rule.output(pbmGraph[i-1][j-1], pbmGraph[i][j-1], 0);
		 		else
		 			pbmGraph[i][j] = rule.output(pbmGraph[i-1][j-1], pbmGraph[i][j-1], pbmGraph[i+1][j-1]);
		 	}
		 }
		 for(j = 0; j < stepCount + 1; j++){
		 	for(i = 0; i < 2 * stepCount + 1; i++)
		 		System.out.print(pbmGraph[i][j] + " ");
		 	System.out.println(); 
		 }
		 return;	
	}
	


	public void printRuleLawArray (){
		int i = 0;

		System.out.println("succsufflly pring :");
		for (i=0;i<8 ;i++ ) {
			System.out.print(rule.ruleLaw[i]);
		}
		System.out.println();
	return;
	}

	// Retrieve the command-line arguments, and convert them to values for the rule number 
	// and the timestep count.
	private void processArgs (String [ ] args) {
		if (args.length != 2) {
			System.err.println ("Usage:  java Life1D rule# rowcount");
			System.exit (1);
		}
		try {
			rule = new Rule (Integer.parseInt (args[0]));
		} catch (IllegalArgumentException ex) {
			System.err.println ("The first argument must specify a rule number.");
			System.exit (1);
		}
		try {
			stepCount = Integer.parseInt (args[1]);
		} catch (Exception ex) {
			System.err.println ("The second argument must specify the number of lines in the output.");
			System.exit (1);
		}
		if (stepCount < 1) {
			System.err.println ("The number of output lines must be a positive number.");
			System.exit (1);
		}
	}
}

class Rule {

	// Whatever instance variables you need should be declared here.
	int[] ruleLaw = new int [8];

	public Rule (int ruleNum) {
		// You fill in the code for this constructor.
		int i,j;

		if (ruleNum <= 255 && ruleNum >= 0){
			for (i=0;i<8;i++)
   				ruleLaw[i] = 0;

   			j = 0;
   			while (ruleNum > 0){
       			ruleLaw[j] = ruleNum % 2;
       			ruleNum /= 2;
       			j++;
        	}
		}
		else{
			 throw new IllegalArgumentException();
		}
	}

	
	// Return the output that this rule prescribes for the given input.
	// a, b, and c are each either 1 or 0; 4*a+2*b+c is the input for the rule.
	
	public int output (int a, int b, int c) {
		return ruleLaw[4 * a + 2 * b + c];
	}
	
}
