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

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 16.1.0 Build 196 10/24/2016 SJ Lite Edition"

-- DATE "05/07/2017 15:48:27"

-- 
-- Device: Altera EP4CE6E22A7 Package TQFP144
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	hard_block IS
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic
	);
END hard_block;

-- Design Ports Information
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_101,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


ARCHITECTURE structure OF hard_block IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~padout\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~padout\ : std_logic;
SIGNAL \~ALTERA_DATA0~~padout\ : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_DATA0~~ibuf_o\ : std_logic;

BEGIN

ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
END structure;


LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	test_mux4 IS
    PORT (
	INPUT : IN std_logic_vector(3 DOWNTO 0);
	SEL : IN std_logic_vector(1 DOWNTO 0);
	OUTPUT : OUT std_logic_vector(3 DOWNTO 0);
	DEC_MON_OUT : OUT std_logic_vector(3 DOWNTO 0)
	);
END test_mux4;

-- Design Ports Information
-- OUTPUT[0]	=>  Location: PIN_49,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OUTPUT[1]	=>  Location: PIN_33,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OUTPUT[2]	=>  Location: PIN_50,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OUTPUT[3]	=>  Location: PIN_68,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[0]	=>  Location: PIN_43,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[1]	=>  Location: PIN_30,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[2]	=>  Location: PIN_44,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[3]	=>  Location: PIN_42,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[3]	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[2]	=>  Location: PIN_38,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SEL[1]	=>  Location: PIN_34,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SEL[0]	=>  Location: PIN_39,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[1]	=>  Location: PIN_46,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[0]	=>  Location: PIN_23,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF test_mux4 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_INPUT : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_SEL : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_OUTPUT : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_DEC_MON_OUT : std_logic_vector(3 DOWNTO 0);
SIGNAL \OUTPUT[0]~output_o\ : std_logic;
SIGNAL \OUTPUT[1]~output_o\ : std_logic;
SIGNAL \OUTPUT[2]~output_o\ : std_logic;
SIGNAL \OUTPUT[3]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[0]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[1]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[2]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[3]~output_o\ : std_logic;
SIGNAL \SEL[1]~input_o\ : std_logic;
SIGNAL \INPUT[2]~input_o\ : std_logic;
SIGNAL \INPUT[3]~input_o\ : std_logic;
SIGNAL \INPUT[0]~input_o\ : std_logic;
SIGNAL \INPUT[1]~input_o\ : std_logic;
SIGNAL \SEL[0]~input_o\ : std_logic;
SIGNAL \OUTPUT~0_combout\ : std_logic;
SIGNAL \OUTPUT~1_combout\ : std_logic;
SIGNAL \Mux0~0_combout\ : std_logic;
SIGNAL \Mux0~1_combout\ : std_logic;
SIGNAL \OUTPUT~2_combout\ : std_logic;
SIGNAL \OUTPUT~3_combout\ : std_logic;
SIGNAL \OUTPUT~4_combout\ : std_logic;
SIGNAL \OUTPUT~5_combout\ : std_logic;
SIGNAL \ALT_INV_OUTPUT~2_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

ww_INPUT <= INPUT;
ww_SEL <= SEL;
OUTPUT <= ww_OUTPUT;
DEC_MON_OUT <= ww_DEC_MON_OUT;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_OUTPUT~2_combout\ <= NOT \OUTPUT~2_combout\;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X13_Y0_N16
\OUTPUT[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~1_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[0]~output_o\);

-- Location: IOOBUF_X0_Y6_N23
\OUTPUT[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux0~1_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[1]~output_o\);

-- Location: IOOBUF_X13_Y0_N2
\OUTPUT[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~1_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[2]~output_o\);

-- Location: IOOBUF_X30_Y0_N9
\OUTPUT[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \OUTPUT[3]~output_o\);

-- Location: IOOBUF_X5_Y0_N23
\DEC_MON_OUT[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_OUTPUT~2_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[0]~output_o\);

-- Location: IOOBUF_X0_Y8_N16
\DEC_MON_OUT[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~3_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[1]~output_o\);

-- Location: IOOBUF_X5_Y0_N16
\DEC_MON_OUT[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~4_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[2]~output_o\);

-- Location: IOOBUF_X3_Y0_N2
\DEC_MON_OUT[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~5_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[3]~output_o\);

-- Location: IOIBUF_X0_Y5_N15
\SEL[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SEL(1),
	o => \SEL[1]~input_o\);

-- Location: IOIBUF_X1_Y0_N22
\INPUT[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(2),
	o => \INPUT[2]~input_o\);

-- Location: IOIBUF_X16_Y0_N22
\INPUT[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(3),
	o => \INPUT[3]~input_o\);

-- Location: IOIBUF_X0_Y11_N8
\INPUT[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(0),
	o => \INPUT[0]~input_o\);

-- Location: IOIBUF_X7_Y0_N1
\INPUT[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(1),
	o => \INPUT[1]~input_o\);

-- Location: IOIBUF_X1_Y0_N15
\SEL[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SEL(0),
	o => \SEL[0]~input_o\);

-- Location: LCCOMB_X6_Y4_N16
\OUTPUT~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~0_combout\ = (\SEL[1]~input_o\ & (((\SEL[0]~input_o\)))) # (!\SEL[1]~input_o\ & ((\SEL[0]~input_o\ & ((\INPUT[1]~input_o\))) # (!\SEL[0]~input_o\ & (\INPUT[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101001000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[0]~input_o\,
	datac => \INPUT[1]~input_o\,
	datad => \SEL[0]~input_o\,
	combout => \OUTPUT~0_combout\);

-- Location: LCCOMB_X6_Y4_N26
\OUTPUT~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~1_combout\ = (\SEL[1]~input_o\ & ((\OUTPUT~0_combout\ & ((\INPUT[3]~input_o\))) # (!\OUTPUT~0_combout\ & (\INPUT[2]~input_o\)))) # (!\SEL[1]~input_o\ & (((\OUTPUT~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010110001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[2]~input_o\,
	datac => \INPUT[3]~input_o\,
	datad => \OUTPUT~0_combout\,
	combout => \OUTPUT~1_combout\);

-- Location: LCCOMB_X6_Y4_N28
\Mux0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux0~0_combout\ = (\SEL[1]~input_o\ & (((\SEL[0]~input_o\)))) # (!\SEL[1]~input_o\ & ((\SEL[0]~input_o\ & ((\INPUT[1]~input_o\))) # (!\SEL[0]~input_o\ & (\INPUT[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101001000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[0]~input_o\,
	datac => \INPUT[1]~input_o\,
	datad => \SEL[0]~input_o\,
	combout => \Mux0~0_combout\);

-- Location: LCCOMB_X6_Y4_N14
\Mux0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux0~1_combout\ = (\SEL[1]~input_o\ & ((\Mux0~0_combout\ & ((\INPUT[3]~input_o\))) # (!\Mux0~0_combout\ & (\INPUT[2]~input_o\)))) # (!\SEL[1]~input_o\ & (((\Mux0~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010110001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[2]~input_o\,
	datac => \INPUT[3]~input_o\,
	datad => \Mux0~0_combout\,
	combout => \Mux0~1_combout\);

-- Location: LCCOMB_X6_Y4_N24
\OUTPUT~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~2_combout\ = (\SEL[1]~input_o\) # (\SEL[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datad => \SEL[0]~input_o\,
	combout => \OUTPUT~2_combout\);

-- Location: LCCOMB_X6_Y4_N10
\OUTPUT~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~3_combout\ = (!\SEL[1]~input_o\ & \SEL[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datad => \SEL[0]~input_o\,
	combout => \OUTPUT~3_combout\);

-- Location: LCCOMB_X6_Y4_N12
\OUTPUT~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~4_combout\ = (\SEL[1]~input_o\ & !\SEL[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datad => \SEL[0]~input_o\,
	combout => \OUTPUT~4_combout\);

-- Location: LCCOMB_X6_Y4_N22
\OUTPUT~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~5_combout\ = (\SEL[1]~input_o\ & \SEL[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datad => \SEL[0]~input_o\,
	combout => \OUTPUT~5_combout\);

ww_OUTPUT(0) <= \OUTPUT[0]~output_o\;

ww_OUTPUT(1) <= \OUTPUT[1]~output_o\;

ww_OUTPUT(2) <= \OUTPUT[2]~output_o\;

ww_OUTPUT(3) <= \OUTPUT[3]~output_o\;

ww_DEC_MON_OUT(0) <= \DEC_MON_OUT[0]~output_o\;

ww_DEC_MON_OUT(1) <= \DEC_MON_OUT[1]~output_o\;

ww_DEC_MON_OUT(2) <= \DEC_MON_OUT[2]~output_o\;

ww_DEC_MON_OUT(3) <= \DEC_MON_OUT[3]~output_o\;
END structure;


