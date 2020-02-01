library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity test_mux is
    Port ( INPUT : in  STD_LOGIC_VECTOR(6 downto 0);
           SEL : in  STD_LOGIC_VECTOR(2 downto 0);
           OUTPUT : out STD_LOGIC_VECTOR(3 downto 0);
           DEC_MON_OUT : out STD_LOGIC_VECTOR(7 downto 0)              
            );
end test_mux;

architecture Behavioral of test_mux is
    signal DEC_OUT: STD_LOGIC_VECTOR(7 downto 0);
    signal DEC_SEL: STD_LOGIC_VECTOR(2 downto 0);

begin
	
	 p1: process (INPUT,SEL)
		begin
			case SEL is
				when "000" =>OUTPUT(3) <= INPUT(0);
				when "001" =>OUTPUT(3) <= INPUT(1);
				when "010" =>OUTPUT(3) <= INPUT(2);
				when "011" =>OUTPUT(3) <= INPUT(3);
				when "100" =>OUTPUT(3) <= INPUT(4);
				when "101" =>OUTPUT(3) <= INPUT(5);
				when "110" =>OUTPUT(3) <= INPUT(6);
				when "111" =>OUTPUT(3) <= '0';
				end case;
			end process;
				
    OUTPUT(0)     <= 	(    SEL(2) and     SEL(1) and not SEL(0) and INPUT(6)) or 
								(    SEL(2) and not SEL(1) and     SEL(0) and INPUT(5)) or 
								(    SEL(2) and not SEL(1) and not SEL(0) and INPUT(4)) or 
								(not SEL(2) and     SEL(1) and     SEL(0) and INPUT(3)) or 
                        (not SEL(2) and     SEL(1) and not SEL(0) and INPUT(2)) or 
                        (not SEL(2) and not SEL(1) and     SEL(0) and INPUT(1)) or    
                        (not SEL(2) and not SEL(1) and not SEL(0) and INPUT(0));
                        
    with SEL select
        OUTPUT(1) <=    	 '0' when "111",
									 INPUT(6) when "110",
									 INPUT(5) when "101",
									 INPUT(4) when "100",
									 INPUT(3) when "011",
                            INPUT(2) when "010",
                            INPUT(1) when "001",
                            INPUT(0) when "000";

    DEC_SEL <= SEL;
    with DEC_SEL select
        DEC_OUT <=    	"00000001" when "000",
								"00000010" when "001",
                        "00000100" when "010",
								"00001000" when "011",
								"00010000" when "100",
								"00100000" when "101",
								"01000000" when "110",
								"00000000" when "111";
								

    DEC_MON_OUT <= DEC_OUT;
    
    OUTPUT(2) <=     	(DEC_OUT(6) and INPUT(6)) or
								(DEC_OUT(5) and INPUT(5)) or
								(DEC_OUT(4) and INPUT(4)) or
								(DEC_OUT(3) and INPUT(3)) or
                        (DEC_OUT(2) and INPUT(2)) or
                        (DEC_OUT(1) and INPUT(1)) or
                        (DEC_OUT(0) and INPUT(0));
								
				
                            
end Behavioral;
