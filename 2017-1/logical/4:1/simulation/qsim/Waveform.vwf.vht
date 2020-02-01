-- Copyright (C) 2016  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Intel and sold by Intel or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- *****************************************************************************
-- This file contains a Vhdl test bench with test vectors .The test vectors     
-- are exported from a vector file in the Quartus Waveform Editor and apply to  
-- the top level entity of the current Quartus project .The user can use this   
-- testbench to simulate his design using a third-party simulation tool .       
-- *****************************************************************************
-- Generated on "05/07/2017 15:57:25"
                                                             
-- Vhdl Test Bench(with test vectors) for design  :          test_mux4
-- 
-- Simulation tool : 3rd Party
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY test_mux4_vhd_vec_tst IS
END test_mux4_vhd_vec_tst;
ARCHITECTURE test_mux4_arch OF test_mux4_vhd_vec_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL DEC_MON_OUT : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL INPUT : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL OUTPUT : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL SEL : STD_LOGIC_VECTOR(1 DOWNTO 0);
COMPONENT test_mux4
	PORT (
	DEC_MON_OUT : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
	INPUT : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	OUTPUT : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
	SEL : IN STD_LOGIC_VECTOR(1 DOWNTO 0)
	);
END COMPONENT;
BEGIN
	i1 : test_mux4
	PORT MAP (
-- list connections between master ports and signals
	DEC_MON_OUT => DEC_MON_OUT,
	INPUT => INPUT,
	OUTPUT => OUTPUT,
	SEL => SEL
	);
-- INPUT[3]
t_prcs_INPUT_3: PROCESS
BEGIN
	INPUT(3) <= '1';
	WAIT FOR 160000 ps;
	INPUT(3) <= '0';
WAIT;
END PROCESS t_prcs_INPUT_3;
-- INPUT[2]
t_prcs_INPUT_2: PROCESS
BEGIN
	INPUT(2) <= '1';
	WAIT FOR 160000 ps;
	INPUT(2) <= '0';
WAIT;
END PROCESS t_prcs_INPUT_2;
-- INPUT[1]
t_prcs_INPUT_1: PROCESS
BEGIN
	INPUT(1) <= '1';
	WAIT FOR 160000 ps;
	INPUT(1) <= '0';
WAIT;
END PROCESS t_prcs_INPUT_1;
-- INPUT[0]
t_prcs_INPUT_0: PROCESS
BEGIN
	INPUT(0) <= '1';
	WAIT FOR 160000 ps;
	INPUT(0) <= '0';
WAIT;
END PROCESS t_prcs_INPUT_0;
-- SEL[1]
t_prcs_SEL_1: PROCESS
BEGIN
	SEL(1) <= '0';
	WAIT FOR 80000 ps;
	SEL(1) <= '1';
	WAIT FOR 80000 ps;
	SEL(1) <= '0';
WAIT;
END PROCESS t_prcs_SEL_1;
-- SEL[0]
t_prcs_SEL_0: PROCESS
BEGIN
	SEL(0) <= '0';
	WAIT FOR 40000 ps;
	SEL(0) <= '1';
	WAIT FOR 40000 ps;
	SEL(0) <= '0';
	WAIT FOR 40000 ps;
	SEL(0) <= '1';
	WAIT FOR 40000 ps;
	SEL(0) <= '0';
WAIT;
END PROCESS t_prcs_SEL_0;
END test_mux4_arch;
