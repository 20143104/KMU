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

-- DATE "05/09/2017 14:24:21"

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

ENTITY 	test_mux IS
    PORT (
	INPUT : IN std_logic_vector(6 DOWNTO 0);
	SEL : IN std_logic_vector(2 DOWNTO 0);
	OUTPUT : BUFFER std_logic_vector(3 DOWNTO 0);
	DEC_MON_OUT : BUFFER std_logic_vector(7 DOWNTO 0)
	);
END test_mux;

-- Design Ports Information
-- OUTPUT[0]	=>  Location: PIN_58,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OUTPUT[1]	=>  Location: PIN_71,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OUTPUT[2]	=>  Location: PIN_46,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OUTPUT[3]	=>  Location: PIN_70,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[0]	=>  Location: PIN_50,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[1]	=>  Location: PIN_30,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[2]	=>  Location: PIN_55,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[3]	=>  Location: PIN_60,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[4]	=>  Location: PIN_49,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[5]	=>  Location: PIN_67,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[6]	=>  Location: PIN_119,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DEC_MON_OUT[7]	=>  Location: PIN_124,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SEL[0]	=>  Location: PIN_77,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SEL[1]	=>  Location: PIN_52,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[4]	=>  Location: PIN_59,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SEL[2]	=>  Location: PIN_54,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[3]	=>  Location: PIN_66,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[2]	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[0]	=>  Location: PIN_65,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[5]	=>  Location: PIN_64,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[1]	=>  Location: PIN_53,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- INPUT[6]	=>  Location: PIN_44,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF test_mux IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_INPUT : std_logic_vector(6 DOWNTO 0);
SIGNAL ww_SEL : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_OUTPUT : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_DEC_MON_OUT : std_logic_vector(7 DOWNTO 0);
SIGNAL \OUTPUT[0]~output_o\ : std_logic;
SIGNAL \OUTPUT[1]~output_o\ : std_logic;
SIGNAL \OUTPUT[2]~output_o\ : std_logic;
SIGNAL \OUTPUT[3]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[0]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[1]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[2]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[3]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[4]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[5]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[6]~output_o\ : std_logic;
SIGNAL \DEC_MON_OUT[7]~output_o\ : std_logic;
SIGNAL \SEL[1]~input_o\ : std_logic;
SIGNAL \INPUT[2]~input_o\ : std_logic;
SIGNAL \INPUT[1]~input_o\ : std_logic;
SIGNAL \INPUT[5]~input_o\ : std_logic;
SIGNAL \SEL[0]~input_o\ : std_logic;
SIGNAL \SEL[2]~input_o\ : std_logic;
SIGNAL \OUTPUT~1_combout\ : std_logic;
SIGNAL \INPUT[0]~input_o\ : std_logic;
SIGNAL \OUTPUT~2_combout\ : std_logic;
SIGNAL \INPUT[4]~input_o\ : std_logic;
SIGNAL \OUTPUT~0_combout\ : std_logic;
SIGNAL \INPUT[3]~input_o\ : std_logic;
SIGNAL \OUTPUT~3_combout\ : std_logic;
SIGNAL \INPUT[6]~input_o\ : std_logic;
SIGNAL \OUTPUT~4_combout\ : std_logic;
SIGNAL \OUTPUT~5_combout\ : std_logic;
SIGNAL \Mux1~3_combout\ : std_logic;
SIGNAL \Mux1~2_combout\ : std_logic;
SIGNAL \Mux1~0_combout\ : std_logic;
SIGNAL \Mux1~1_combout\ : std_logic;
SIGNAL \Mux1~4_combout\ : std_logic;
SIGNAL \Mux8~3_combout\ : std_logic;
SIGNAL \Mux8~4_combout\ : std_logic;
SIGNAL \OUTPUT~8_combout\ : std_logic;
SIGNAL \Mux8~5_combout\ : std_logic;
SIGNAL \Mux8~0_combout\ : std_logic;
SIGNAL \Mux8~1_combout\ : std_logic;
SIGNAL \OUTPUT~6_combout\ : std_logic;
SIGNAL \Mux8~2_combout\ : std_logic;
SIGNAL \OUTPUT~7_combout\ : std_logic;
SIGNAL \OUTPUT~9_combout\ : std_logic;
SIGNAL \Mux8~6_combout\ : std_logic;

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
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X21_Y0_N9
\OUTPUT[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~5_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[0]~output_o\);

-- Location: IOOBUF_X32_Y0_N16
\OUTPUT[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux1~4_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[1]~output_o\);

-- Location: IOOBUF_X7_Y0_N2
\OUTPUT[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \OUTPUT~9_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[2]~output_o\);

-- Location: IOOBUF_X32_Y0_N23
\OUTPUT[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux1~4_combout\,
	devoe => ww_devoe,
	o => \OUTPUT[3]~output_o\);

-- Location: IOOBUF_X13_Y0_N2
\DEC_MON_OUT[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux8~4_combout\,
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
	i => \Mux8~3_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[1]~output_o\);

-- Location: IOOBUF_X18_Y0_N16
\DEC_MON_OUT[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux8~5_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[2]~output_o\);

-- Location: IOOBUF_X23_Y0_N9
\DEC_MON_OUT[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux8~2_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[3]~output_o\);

-- Location: IOOBUF_X13_Y0_N16
\DEC_MON_OUT[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux8~6_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[4]~output_o\);

-- Location: IOOBUF_X30_Y0_N23
\DEC_MON_OUT[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux8~0_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[5]~output_o\);

-- Location: IOOBUF_X23_Y24_N2
\DEC_MON_OUT[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux8~1_combout\,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[6]~output_o\);

-- Location: IOOBUF_X18_Y24_N16
\DEC_MON_OUT[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \DEC_MON_OUT[7]~output_o\);

-- Location: IOIBUF_X16_Y0_N8
\SEL[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SEL(1),
	o => \SEL[1]~input_o\);

-- Location: IOIBUF_X16_Y0_N22
\INPUT[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(2),
	o => \INPUT[2]~input_o\);

-- Location: IOIBUF_X16_Y0_N1
\INPUT[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(1),
	o => \INPUT[1]~input_o\);

-- Location: IOIBUF_X25_Y0_N1
\INPUT[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(5),
	o => \INPUT[5]~input_o\);

-- Location: IOIBUF_X34_Y4_N15
\SEL[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SEL(0),
	o => \SEL[0]~input_o\);

-- Location: IOIBUF_X18_Y0_N22
\SEL[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SEL(2),
	o => \SEL[2]~input_o\);

-- Location: LCCOMB_X24_Y4_N26
\OUTPUT~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~1_combout\ = (\SEL[0]~input_o\ & ((\SEL[2]~input_o\ & ((\INPUT[5]~input_o\))) # (!\SEL[2]~input_o\ & (\INPUT[1]~input_o\)))) # (!\SEL[0]~input_o\ & (((\SEL[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \INPUT[1]~input_o\,
	datab => \INPUT[5]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \SEL[2]~input_o\,
	combout => \OUTPUT~1_combout\);

-- Location: IOIBUF_X28_Y0_N22
\INPUT[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(0),
	o => \INPUT[0]~input_o\);

-- Location: LCCOMB_X24_Y4_N12
\OUTPUT~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~2_combout\ = (\SEL[1]~input_o\ & ((\INPUT[2]~input_o\) # ((\OUTPUT~1_combout\)))) # (!\SEL[1]~input_o\ & (((!\OUTPUT~1_combout\ & \INPUT[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110110101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[2]~input_o\,
	datac => \OUTPUT~1_combout\,
	datad => \INPUT[0]~input_o\,
	combout => \OUTPUT~2_combout\);

-- Location: IOIBUF_X23_Y0_N15
\INPUT[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(4),
	o => \INPUT[4]~input_o\);

-- Location: LCCOMB_X24_Y4_N0
\OUTPUT~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~0_combout\ = (\SEL[1]~input_o\ & (\INPUT[4]~input_o\ & (\SEL[0]~input_o\ & !\SEL[2]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[4]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \SEL[2]~input_o\,
	combout => \OUTPUT~0_combout\);

-- Location: IOIBUF_X28_Y0_N1
\INPUT[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(3),
	o => \INPUT[3]~input_o\);

-- Location: LCCOMB_X24_Y4_N14
\OUTPUT~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~3_combout\ = (\SEL[0]~input_o\) # ((!\OUTPUT~2_combout\ & \INPUT[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010011110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \OUTPUT~2_combout\,
	datab => \INPUT[3]~input_o\,
	datac => \SEL[0]~input_o\,
	combout => \OUTPUT~3_combout\);

-- Location: IOIBUF_X5_Y0_N15
\INPUT[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_INPUT(6),
	o => \INPUT[6]~input_o\);

-- Location: LCCOMB_X24_Y4_N16
\OUTPUT~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~4_combout\ = (\OUTPUT~1_combout\ & ((!\OUTPUT~2_combout\) # (!\INPUT[6]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \OUTPUT~1_combout\,
	datac => \INPUT[6]~input_o\,
	datad => \OUTPUT~2_combout\,
	combout => \OUTPUT~4_combout\);

-- Location: LCCOMB_X24_Y4_N2
\OUTPUT~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~5_combout\ = (\OUTPUT~0_combout\) # ((\OUTPUT~2_combout\ & (!\OUTPUT~3_combout\ & !\OUTPUT~4_combout\)) # (!\OUTPUT~2_combout\ & (\OUTPUT~3_combout\ & \OUTPUT~4_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110011001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \OUTPUT~2_combout\,
	datab => \OUTPUT~0_combout\,
	datac => \OUTPUT~3_combout\,
	datad => \OUTPUT~4_combout\,
	combout => \OUTPUT~5_combout\);

-- Location: LCCOMB_X24_Y4_N10
\Mux1~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~3_combout\ = (!\SEL[0]~input_o\ & ((\SEL[1]~input_o\ & ((\INPUT[6]~input_o\))) # (!\SEL[1]~input_o\ & (\INPUT[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[3]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \INPUT[6]~input_o\,
	combout => \Mux1~3_combout\);

-- Location: LCCOMB_X24_Y4_N8
\Mux1~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~2_combout\ = (!\SEL[1]~input_o\ & (\SEL[0]~input_o\ & \INPUT[5]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \INPUT[5]~input_o\,
	combout => \Mux1~2_combout\);

-- Location: LCCOMB_X24_Y4_N4
\Mux1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~0_combout\ = (\SEL[1]~input_o\ & ((\INPUT[2]~input_o\) # ((\SEL[0]~input_o\)))) # (!\SEL[1]~input_o\ & (((!\SEL[0]~input_o\ & \INPUT[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110110101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datab => \INPUT[2]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \INPUT[0]~input_o\,
	combout => \Mux1~0_combout\);

-- Location: LCCOMB_X24_Y4_N6
\Mux1~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~1_combout\ = (\Mux1~0_combout\ & (((\INPUT[4]~input_o\) # (!\SEL[0]~input_o\)))) # (!\Mux1~0_combout\ & (\INPUT[1]~input_o\ & (\SEL[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110110000101100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \INPUT[1]~input_o\,
	datab => \Mux1~0_combout\,
	datac => \SEL[0]~input_o\,
	datad => \INPUT[4]~input_o\,
	combout => \Mux1~1_combout\);

-- Location: LCCOMB_X24_Y4_N20
\Mux1~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~4_combout\ = (\SEL[2]~input_o\ & ((\Mux1~3_combout\) # ((\Mux1~2_combout\)))) # (!\SEL[2]~input_o\ & (((\Mux1~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111111100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Mux1~3_combout\,
	datab => \Mux1~2_combout\,
	datac => \SEL[2]~input_o\,
	datad => \Mux1~1_combout\,
	combout => \Mux1~4_combout\);

-- Location: LCCOMB_X19_Y3_N0
\Mux8~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~3_combout\ = (\SEL[0]~input_o\ & (!\SEL[2]~input_o\ & !\SEL[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000001000000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[0]~input_o\,
	datab => \SEL[2]~input_o\,
	datac => \SEL[1]~input_o\,
	combout => \Mux8~3_combout\);

-- Location: LCCOMB_X19_Y3_N26
\Mux8~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~4_combout\ = (!\SEL[0]~input_o\ & (!\SEL[2]~input_o\ & !\SEL[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[0]~input_o\,
	datab => \SEL[2]~input_o\,
	datac => \SEL[1]~input_o\,
	combout => \Mux8~4_combout\);

-- Location: LCCOMB_X19_Y3_N12
\OUTPUT~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~8_combout\ = (\INPUT[1]~input_o\ & ((\Mux8~3_combout\) # ((\Mux8~4_combout\ & \INPUT[0]~input_o\)))) # (!\INPUT[1]~input_o\ & (((\Mux8~4_combout\ & \INPUT[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \INPUT[1]~input_o\,
	datab => \Mux8~3_combout\,
	datac => \Mux8~4_combout\,
	datad => \INPUT[0]~input_o\,
	combout => \OUTPUT~8_combout\);

-- Location: LCCOMB_X19_Y3_N22
\Mux8~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~5_combout\ = (!\SEL[0]~input_o\ & (!\SEL[2]~input_o\ & \SEL[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[0]~input_o\,
	datab => \SEL[2]~input_o\,
	datac => \SEL[1]~input_o\,
	combout => \Mux8~5_combout\);

-- Location: LCCOMB_X24_Y4_N22
\Mux8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~0_combout\ = (!\SEL[1]~input_o\ & (\SEL[0]~input_o\ & \SEL[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \SEL[2]~input_o\,
	combout => \Mux8~0_combout\);

-- Location: LCCOMB_X24_Y4_N24
\Mux8~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~1_combout\ = (\SEL[1]~input_o\ & (!\SEL[0]~input_o\ & \SEL[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \SEL[2]~input_o\,
	combout => \Mux8~1_combout\);

-- Location: LCCOMB_X24_Y4_N18
\OUTPUT~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~6_combout\ = (\Mux8~0_combout\ & ((\INPUT[5]~input_o\) # ((\Mux8~1_combout\ & \INPUT[6]~input_o\)))) # (!\Mux8~0_combout\ & (\Mux8~1_combout\ & (\INPUT[6]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110101011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Mux8~0_combout\,
	datab => \Mux8~1_combout\,
	datac => \INPUT[6]~input_o\,
	datad => \INPUT[5]~input_o\,
	combout => \OUTPUT~6_combout\);

-- Location: LCCOMB_X24_Y4_N28
\Mux8~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~2_combout\ = (!\SEL[1]~input_o\ & (!\SEL[0]~input_o\ & \SEL[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[1]~input_o\,
	datac => \SEL[0]~input_o\,
	datad => \SEL[2]~input_o\,
	combout => \Mux8~2_combout\);

-- Location: LCCOMB_X24_Y4_N30
\OUTPUT~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~7_combout\ = (\OUTPUT~6_combout\) # ((\OUTPUT~0_combout\) # ((\INPUT[3]~input_o\ & \Mux8~2_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \OUTPUT~6_combout\,
	datab => \OUTPUT~0_combout\,
	datac => \INPUT[3]~input_o\,
	datad => \Mux8~2_combout\,
	combout => \OUTPUT~7_combout\);

-- Location: LCCOMB_X19_Y3_N16
\OUTPUT~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \OUTPUT~9_combout\ = (\OUTPUT~8_combout\) # ((\OUTPUT~7_combout\) # ((\INPUT[2]~input_o\ & \Mux8~5_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \OUTPUT~8_combout\,
	datab => \INPUT[2]~input_o\,
	datac => \Mux8~5_combout\,
	datad => \OUTPUT~7_combout\,
	combout => \OUTPUT~9_combout\);

-- Location: LCCOMB_X19_Y3_N2
\Mux8~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux8~6_combout\ = (\SEL[0]~input_o\ & (!\SEL[2]~input_o\ & \SEL[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SEL[0]~input_o\,
	datab => \SEL[2]~input_o\,
	datac => \SEL[1]~input_o\,
	combout => \Mux8~6_combout\);

ww_OUTPUT(0) <= \OUTPUT[0]~output_o\;

ww_OUTPUT(1) <= \OUTPUT[1]~output_o\;

ww_OUTPUT(2) <= \OUTPUT[2]~output_o\;

ww_OUTPUT(3) <= \OUTPUT[3]~output_o\;

ww_DEC_MON_OUT(0) <= \DEC_MON_OUT[0]~output_o\;

ww_DEC_MON_OUT(1) <= \DEC_MON_OUT[1]~output_o\;

ww_DEC_MON_OUT(2) <= \DEC_MON_OUT[2]~output_o\;

ww_DEC_MON_OUT(3) <= \DEC_MON_OUT[3]~output_o\;

ww_DEC_MON_OUT(4) <= \DEC_MON_OUT[4]~output_o\;

ww_DEC_MON_OUT(5) <= \DEC_MON_OUT[5]~output_o\;

ww_DEC_MON_OUT(6) <= \DEC_MON_OUT[6]~output_o\;

ww_DEC_MON_OUT(7) <= \DEC_MON_OUT[7]~output_o\;
END structure;


