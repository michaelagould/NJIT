public class Rational extends Number implements Comparable<Rational>{
	
		private int numerator;
		private int denominator;
		private int gcd;
	
		public double doubleValue(){return numerator/denominator;}
		public float floatValue(){return numerator/denominator;}
		public int intValue(){return numerator/denominator;}
		public long longValue(){return numerator/denominator;}
	
		public Rational(int numerator, int denominator){

			int gcd = gcd(numerator,denominator);
			this.numerator = numerator/gcd;
			this.denominator = denominator/gcd;
		}

		private int gcd(int first, int second){
			if (second == 0)
				return first;
			return gcd(second, first%second);
		}
		
		private Rational makeDenominatorSame(Rational o){
		
			if(this.denominator == o.denominator)
				return this;
			return new Rational(o.denominator * numerator, o.denominator * denominator);
		}
		
		public Rational add(Rational o){
		
			Rational tempA = this.makeDenominatorSame(o);
			Rational tempB = o.makeDenominatorSame(this);
			return new Rational(tempA.numerator + tempB.numerator, tempA.denominator);
		}


		public Rational sub(Rational o){

			Rational tempA = this.makeDenominatorSame(o);
			Rational tempB = o.makeDenominatorSame(this);
			return new Rational(tempA.numerator - tempB.numerator, tempA.denominator);
		}

		public Rational mul(Rational o){return new Rational(numerator * o.numerator, denominator * o.denominator);}
		public Rational div(Rational o){return new Rational(numerator * o.denominator, denominator * o.numerator);}
		public String toString(){return "(" + numerator + "/" + denominator + ")";}

		public int compareTo(Rational a){

			if(this.floatValue() < a.floatValue())
				return -1;
			else if(this.floatValue() > a.floatValue())
				return 1;
			else
				return 0;
		}

	}