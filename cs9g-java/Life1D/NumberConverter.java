public class NumberConverter {
   public static void main(String[] args) {
       int i = Integer.parseInt(args[0]);
       toBinary(i);
   }

   public static void toBinary(int int1)
   {
   		int i;
   		int j = 7;
   		int[] ruleLaw = new int [8];

   		for (i=0;i<8;i++)
   			ruleLaw[i] = 0;

       	while (int1 > 0)
       	{
       		ruleLaw[j] = int1 % 2;
       		int1 /= 2;
       		j--;
        }
   }
}