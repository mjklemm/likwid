/*
 * =======================================================================================
 *
 *      Filename:  perfmon_ivybridgeEP_counters.h
 *
 *      Description: Counter header file of perfmon module for Intel Ivy Bridge EP.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *                Thomas Roehl (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2015 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_CORE_IVYBRIDGEEP 8
#define NUM_COUNTERS_UNCORE_IVYBRIDGEEP 81
#define NUM_COUNTERS_IVYBRIDGEEP 161

#define IVB_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_INVERT_MASK|\
            EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVB_VALID_OPTIONS_FIXED EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_COUNT_KERNEL_MASK
#define IVB_VALID_OPTIONS_UBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVB_VALID_OPTIONS_CBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_TID_MASK|EVENT_OPTION_STATE_MASK|EVENT_OPTION_NID_MASK|\
            EVENT_OPTION_OPCODE_MASK|EVENT_OPTION_MATCH0_MASK
#define IVB_VALID_OPTIONS_WBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_OCCUPANCY_MASK|EVENT_OPTION_OCCUPANCY_FILTER_MASK|EVENT_OPTION_OCCUPANCY_EDGE_MASK|\
            EVENT_OPTION_OCCUPANCY_INVERT_MASK
#define IVB_VALID_OPTIONS_MBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVB_VALID_OPTIONS_SBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_MATCH0_MASK|EVENT_OPTION_MATCH1_MASK|EVENT_OPTION_MASK0_MASK|\
            EVENT_OPTION_MASK0_MASK
#define IVB_VALID_OPTIONS_BBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_OPCODE_MASK|EVENT_OPTION_MATCH0_MASK
#define IVB_VALID_OPTIONS_PBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVB_VALID_OPTIONS_RBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVB_VALID_OPTIONS_IBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK


static RegisterMap ivybridgeEP_counter_map[NUM_COUNTERS_IVYBRIDGEEP] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, IVB_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, IVB_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, IVB_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, IVB_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, IVB_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, IVB_VALID_OPTIONS_PMC},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, IVB_VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC7, THERMAL, 0, IA32_THERM_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC8, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC9, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC10, POWER, 0, MSR_PP1_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC11, POWER, 0, MSR_DRAM_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* CBOX counters, 44bits wide*/
    {"CBOX0C0", PMC12, CBOX0, MSR_UNC_C0_PMON_CTL0, MSR_UNC_C0_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC13, CBOX0, MSR_UNC_C0_PMON_CTL1, MSR_UNC_C0_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX0C2", PMC14, CBOX0, MSR_UNC_C0_PMON_CTL2, MSR_UNC_C0_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX0C3", PMC15, CBOX0, MSR_UNC_C0_PMON_CTL3, MSR_UNC_C0_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC16, CBOX1, MSR_UNC_C1_PMON_CTL0, MSR_UNC_C1_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC17, CBOX1, MSR_UNC_C1_PMON_CTL1, MSR_UNC_C1_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX1C2", PMC18, CBOX1, MSR_UNC_C1_PMON_CTL2, MSR_UNC_C1_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX1C3", PMC19, CBOX1, MSR_UNC_C1_PMON_CTL3, MSR_UNC_C1_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC20, CBOX2, MSR_UNC_C2_PMON_CTL0, MSR_UNC_C2_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC21, CBOX2, MSR_UNC_C2_PMON_CTL1, MSR_UNC_C2_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX2C2", PMC22, CBOX2, MSR_UNC_C2_PMON_CTL2, MSR_UNC_C2_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX2C3", PMC23, CBOX2, MSR_UNC_C2_PMON_CTL3, MSR_UNC_C2_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC24, CBOX3, MSR_UNC_C3_PMON_CTL0, MSR_UNC_C3_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC25, CBOX3, MSR_UNC_C3_PMON_CTL1, MSR_UNC_C3_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX3C2", PMC26, CBOX3, MSR_UNC_C3_PMON_CTL2, MSR_UNC_C3_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX3C3", PMC27, CBOX3, MSR_UNC_C3_PMON_CTL3, MSR_UNC_C3_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX4C0", PMC28, CBOX4, MSR_UNC_C4_PMON_CTL0, MSR_UNC_C4_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX4C1", PMC29, CBOX4, MSR_UNC_C4_PMON_CTL1, MSR_UNC_C4_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX4C2", PMC30, CBOX4, MSR_UNC_C4_PMON_CTL2, MSR_UNC_C4_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX4C3", PMC31, CBOX4, MSR_UNC_C4_PMON_CTL3, MSR_UNC_C4_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX5C0", PMC32, CBOX5, MSR_UNC_C5_PMON_CTL0, MSR_UNC_C5_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX5C1", PMC33, CBOX5, MSR_UNC_C5_PMON_CTL1, MSR_UNC_C5_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX5C2", PMC34, CBOX5, MSR_UNC_C5_PMON_CTL2, MSR_UNC_C5_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX5C3", PMC35, CBOX5, MSR_UNC_C5_PMON_CTL3, MSR_UNC_C5_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX6C0", PMC36, CBOX6, MSR_UNC_C6_PMON_CTL0, MSR_UNC_C6_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX6C1", PMC37, CBOX6, MSR_UNC_C6_PMON_CTL1, MSR_UNC_C6_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX6C2", PMC38, CBOX6, MSR_UNC_C6_PMON_CTL2, MSR_UNC_C6_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX6C3", PMC39, CBOX6, MSR_UNC_C6_PMON_CTL3, MSR_UNC_C6_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX7C0", PMC40, CBOX7, MSR_UNC_C7_PMON_CTL0, MSR_UNC_C7_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX7C1", PMC41, CBOX7, MSR_UNC_C7_PMON_CTL1, MSR_UNC_C7_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX7C2", PMC42, CBOX7, MSR_UNC_C7_PMON_CTL2, MSR_UNC_C7_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX7C3", PMC43, CBOX7, MSR_UNC_C7_PMON_CTL3, MSR_UNC_C7_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX8C0", PMC44, CBOX8, MSR_UNC_C8_PMON_CTL0, MSR_UNC_C8_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX8C1", PMC45, CBOX8, MSR_UNC_C8_PMON_CTL1, MSR_UNC_C8_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX8C2", PMC46, CBOX8, MSR_UNC_C8_PMON_CTL2, MSR_UNC_C8_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX8C3", PMC47, CBOX8, MSR_UNC_C8_PMON_CTL3, MSR_UNC_C8_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX9C0", PMC48, CBOX9, MSR_UNC_C9_PMON_CTL0, MSR_UNC_C9_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX9C1", PMC49, CBOX9, MSR_UNC_C9_PMON_CTL1, MSR_UNC_C9_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX9C2", PMC50, CBOX9, MSR_UNC_C9_PMON_CTL2, MSR_UNC_C9_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX9C3", PMC51, CBOX9, MSR_UNC_C9_PMON_CTL3, MSR_UNC_C9_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX10C0", PMC52, CBOX10, MSR_UNC_C10_PMON_CTL0, MSR_UNC_C10_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX10C1", PMC53, CBOX10, MSR_UNC_C10_PMON_CTL1, MSR_UNC_C10_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX10C2", PMC54, CBOX10, MSR_UNC_C10_PMON_CTL2, MSR_UNC_C10_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX10C3", PMC55, CBOX10, MSR_UNC_C10_PMON_CTL3, MSR_UNC_C10_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX11C0", PMC56, CBOX11, MSR_UNC_C11_PMON_CTL0, MSR_UNC_C11_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX11C1", PMC57, CBOX11, MSR_UNC_C11_PMON_CTL1, MSR_UNC_C11_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX11C2", PMC58, CBOX11, MSR_UNC_C11_PMON_CTL2, MSR_UNC_C11_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX11C3", PMC59, CBOX11, MSR_UNC_C11_PMON_CTL3, MSR_UNC_C11_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX12C0", PMC60, CBOX12, MSR_UNC_C12_PMON_CTL0, MSR_UNC_C12_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX12C1", PMC61, CBOX12, MSR_UNC_C12_PMON_CTL1, MSR_UNC_C12_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX12C2", PMC62, CBOX12, MSR_UNC_C12_PMON_CTL2, MSR_UNC_C12_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX12C3", PMC63, CBOX12, MSR_UNC_C12_PMON_CTL3, MSR_UNC_C12_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX13C0", PMC64, CBOX13, MSR_UNC_C13_PMON_CTL0, MSR_UNC_C13_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX13C1", PMC65, CBOX13, MSR_UNC_C13_PMON_CTL1, MSR_UNC_C13_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX13C2", PMC66, CBOX13, MSR_UNC_C13_PMON_CTL2, MSR_UNC_C13_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX13C3", PMC67, CBOX13, MSR_UNC_C13_PMON_CTL3, MSR_UNC_C13_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX14C0", PMC68, CBOX14, MSR_UNC_C14_PMON_CTL0, MSR_UNC_C14_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX14C1", PMC69, CBOX14, MSR_UNC_C14_PMON_CTL1, MSR_UNC_C14_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX14C2", PMC70, CBOX14, MSR_UNC_C14_PMON_CTL2, MSR_UNC_C14_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_CBOX},
    {"CBOX14C3", PMC71, CBOX14, MSR_UNC_C14_PMON_CTL3, MSR_UNC_C14_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_CBOX},
    /* Uncore management Counters: 2 48bit wide counters */
    {"UBOX0", PMC72, UBOX, MSR_UNC_U_PMON_CTL0, MSR_UNC_U_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_UBOX},
    {"UBOX1", PMC73, UBOX, MSR_UNC_U_PMON_CTL1, MSR_UNC_U_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_UBOX},
    {"UBOXFIX", PMC74, UBOXFIX, MSR_UNC_U_UCLK_FIXED_CTL, MSR_UNC_U_UCLK_FIXED_CTR, 0, 0, 0},
    /* PCU Counters: 4 48bit wide counters */
    {"WBOX0", PMC75, WBOX, MSR_UNC_PCU_PMON_CTL0, MSR_UNC_PCU_PMON_CTR0, 0, 0, IVB_VALID_OPTIONS_WBOX},
    {"WBOX1", PMC76, WBOX, MSR_UNC_PCU_PMON_CTL1, MSR_UNC_PCU_PMON_CTR1, 0, 0, IVB_VALID_OPTIONS_WBOX},
    {"WBOX2", PMC77, WBOX, MSR_UNC_PCU_PMON_CTL2, MSR_UNC_PCU_PMON_CTR2, 0, 0, IVB_VALID_OPTIONS_WBOX},
    {"WBOX3", PMC78, WBOX, MSR_UNC_PCU_PMON_CTL3, MSR_UNC_PCU_PMON_CTR3, 0, 0, IVB_VALID_OPTIONS_WBOX},
    {"WBOX0FIX", PMC79, WBOX0FIX, 0, MSR_UNC_PCU_PMON_FIXED_CTR0, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX1FIX", PMC80, WBOX1FIX, 0, MSR_UNC_PCU_PMON_FIXED_CTR1, 0, 0, EVENT_OPTION_NONE_MASK},
    /* IMC Counters: 4 48bit wide per memory channel, split in two reads */
    {"MBOX0C0",PMC81, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX0C1",PMC82, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX0C2",PMC83, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX0C3",PMC84, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX0FIX",PMC85, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX1C0",PMC86, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX1C1",PMC87, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX1C2",PMC88, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX1C3",PMC89, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX1FIX",PMC90, MBOX1FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX2C0",PMC91, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX2C1",PMC92, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX2C2",PMC93, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX2C3",PMC94, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX2FIX",PMC95, MBOX2FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX3C0",PMC96, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX3C1",PMC97, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX3C2",PMC98, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX3C3",PMC99, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX3FIX",PMC100, MBOX3FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    {"MBOX4C0",PMC101, MBOX4, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX4C1",PMC102, MBOX4, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX4C2",PMC103, MBOX4, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX4C3",PMC104, MBOX4, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_0, IVB_VALID_OPTIONS_MBOX},
    {"MBOX4FIX",PMC105, MBOX4FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX5C0",PMC106, MBOX5, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX5C1",PMC107, MBOX5, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX5C2",PMC108, MBOX5, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX5C3",PMC109, MBOX5, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_1, IVB_VALID_OPTIONS_MBOX},
    {"MBOX5FIX",PMC110, MBOX5FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX6C0",PMC111, MBOX6, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX6C1",PMC112, MBOX6, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX6C2",PMC113, MBOX6, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX6C3",PMC114, MBOX6, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_2, IVB_VALID_OPTIONS_MBOX},
    {"MBOX6FIX",PMC115, MBOX6FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX7C0",PMC116, MBOX7, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX7C1",PMC117, MBOX7, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX7C2",PMC118, MBOX7, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX7C3",PMC119, MBOX7, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_3, IVB_VALID_OPTIONS_MBOX},
    {"MBOX7FIX",PMC120, MBOX7FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_3, EVENT_OPTION_NONE_MASK},
    /* QPI counters four 48bit wide per port, split in two reads */
    {"SBOX0C0",PMC121, SBOX0, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_0, IVB_VALID_OPTIONS_SBOX},
    {"SBOX0C1",PMC122, SBOX0, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_0, IVB_VALID_OPTIONS_SBOX},
    {"SBOX0C2",PMC123, SBOX0, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_0, IVB_VALID_OPTIONS_SBOX},
    {"SBOX0C3",PMC124, SBOX0, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_0, IVB_VALID_OPTIONS_SBOX},
    {"SBOX1C0",PMC125, SBOX1, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_1, IVB_VALID_OPTIONS_SBOX},
    {"SBOX1C1",PMC126, SBOX1, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_1, IVB_VALID_OPTIONS_SBOX},
    {"SBOX1C2",PMC127, SBOX1, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_1, IVB_VALID_OPTIONS_SBOX},
    {"SBOX1C3",PMC128, SBOX1, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_1, IVB_VALID_OPTIONS_SBOX},
    {"SBOX2C0",PMC129, SBOX2, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_2, IVB_VALID_OPTIONS_SBOX},
    {"SBOX2C1",PMC130, SBOX2, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_2, IVB_VALID_OPTIONS_SBOX},
    {"SBOX2C2",PMC131, SBOX2, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_2, IVB_VALID_OPTIONS_SBOX},
    {"SBOX2C3",PMC132, SBOX2, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_2, IVB_VALID_OPTIONS_SBOX},
    {"SBOX0FIX",PMC133, SBOX0FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX1FIX",PMC134, SBOX1FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX2FIX",PMC135, SBOX2FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_2, EVENT_OPTION_NONE_MASK},
    /* HA counters four 48bit wide per counter, split in two reads */
    {"BBOX0C0", PMC136, BBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_0, IVB_VALID_OPTIONS_BBOX},
    {"BBOX0C1", PMC137, BBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_0, IVB_VALID_OPTIONS_BBOX},
    {"BBOX0C2", PMC138, BBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_0, IVB_VALID_OPTIONS_BBOX},
    {"BBOX0C3", PMC139, BBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_0, IVB_VALID_OPTIONS_BBOX},
    {"BBOX1C0", PMC140, BBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_1, IVB_VALID_OPTIONS_BBOX},
    {"BBOX1C1", PMC141, BBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_1, IVB_VALID_OPTIONS_BBOX},
    {"BBOX1C2", PMC142, BBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_1, IVB_VALID_OPTIONS_BBOX},
    {"BBOX1C3", PMC143, BBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_1, IVB_VALID_OPTIONS_BBOX},
    /* R2PCIe counters four 44bit wide per counter, split in two reads */
    {"PBOX0", PMC144, PBOX, PCI_UNC_R2PCIE_PMON_CTL_0, PCI_UNC_R2PCIE_PMON_CTR_0_A, PCI_UNC_R2PCIE_PMON_CTR_0_B, PCI_R2PCIE_DEVICE, IVB_VALID_OPTIONS_PBOX},
    {"PBOX1", PMC145, PBOX, PCI_UNC_R2PCIE_PMON_CTL_1, PCI_UNC_R2PCIE_PMON_CTR_1_A, PCI_UNC_R2PCIE_PMON_CTR_1_B, PCI_R2PCIE_DEVICE, IVB_VALID_OPTIONS_PBOX},
    {"PBOX2", PMC146, PBOX, PCI_UNC_R2PCIE_PMON_CTL_2, PCI_UNC_R2PCIE_PMON_CTR_2_A, PCI_UNC_R2PCIE_PMON_CTR_2_B, PCI_R2PCIE_DEVICE, IVB_VALID_OPTIONS_PBOX},
    {"PBOX3", PMC147, PBOX, PCI_UNC_R2PCIE_PMON_CTL_3, PCI_UNC_R2PCIE_PMON_CTR_3_A, PCI_UNC_R2PCIE_PMON_CTR_3_B, PCI_R2PCIE_DEVICE, IVB_VALID_OPTIONS_PBOX},
    /* R3QPI counters four 44bit wide per counter, split in two reads */
    {"RBOX0C0", PMC148, RBOX0, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_0, IVB_VALID_OPTIONS_RBOX},
    {"RBOX0C1", PMC149, RBOX0, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_0, IVB_VALID_OPTIONS_RBOX},
    {"RBOX0C2", PMC150, RBOX0, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_0, IVB_VALID_OPTIONS_RBOX},
    {"RBOX1C0", PMC151, RBOX1, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_1, IVB_VALID_OPTIONS_RBOX},
    {"RBOX1C1", PMC152, RBOX1, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_1, IVB_VALID_OPTIONS_RBOX},
    {"RBOX1C2", PMC153, RBOX1, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_1, IVB_VALID_OPTIONS_RBOX},
    {"RBOX2C0", PMC154, RBOX2, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_2, IVB_VALID_OPTIONS_RBOX},
    {"RBOX2C1", PMC155, RBOX2, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_2, IVB_VALID_OPTIONS_RBOX},
    {"RBOX2C2", PMC156, RBOX2, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_2, IVB_VALID_OPTIONS_RBOX},
    /* IRP counters four 44bit wide per counter */
    {"IBOX0C0", PMC157, IBOX0, PCI_UNC_IRP0_PMON_CTL_0, PCI_UNC_IRP0_PMON_CTR_0, 0, PCI_IRP_DEVICE, IVB_VALID_OPTIONS_IBOX},
    {"IBOX0C1", PMC158, IBOX0, PCI_UNC_IRP0_PMON_CTL_1, PCI_UNC_IRP0_PMON_CTR_1, 0, PCI_IRP_DEVICE, IVB_VALID_OPTIONS_IBOX},
    {"IBOX1C0", PMC159, IBOX1, PCI_UNC_IRP1_PMON_CTL_0, PCI_UNC_IRP1_PMON_CTR_0, 0, PCI_IRP_DEVICE, IVB_VALID_OPTIONS_IBOX},
    {"IBOX1C1", PMC160, IBOX1, PCI_UNC_IRP1_PMON_CTL_1, PCI_UNC_IRP1_PMON_CTR_1, 0, PCI_IRP_DEVICE, IVB_VALID_OPTIONS_IBOX},
};

static BoxMap ivybridgeEP_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, -1, 0, 0, 48},
    [FIXED] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, -1, 0, 0, 48},
    [THERMAL] = {0, 0, 0, 0, 0, MSR_DEV, 8},
    [POWER] = {0, 0, 0, 0, 0, MSR_DEV, 32},
    [MBOX0] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX0FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX1] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX1FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX2] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX2FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX3] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX3FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX4] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX4FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX5] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX5FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX6] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX6FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX7] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [MBOX7FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [CBOX0] = {MSR_UNC_C0_PMON_BOX_CTL, 0, 0, 3, 0, 0, 44, MSR_UNC_C0_PMON_BOX_FILTER, MSR_UNC_C0_PMON_BOX_FILTER1},
    [CBOX1] = {MSR_UNC_C1_PMON_BOX_CTL, 0, 0, 4, 0, 0, 44, MSR_UNC_C1_PMON_BOX_FILTER, MSR_UNC_C1_PMON_BOX_FILTER1},
    [CBOX2] = {MSR_UNC_C2_PMON_BOX_CTL, 0, 0, 5, 0, 0, 44, MSR_UNC_C2_PMON_BOX_FILTER, MSR_UNC_C2_PMON_BOX_FILTER1},
    [CBOX3] = {MSR_UNC_C3_PMON_BOX_CTL, 0, 0, 6, 0, 0, 44, MSR_UNC_C3_PMON_BOX_FILTER, MSR_UNC_C3_PMON_BOX_FILTER1},
    [CBOX4] = {MSR_UNC_C4_PMON_BOX_CTL, 0, 0, 7, 0, 0, 44, MSR_UNC_C4_PMON_BOX_FILTER, MSR_UNC_C4_PMON_BOX_FILTER1},
    [CBOX5] = {MSR_UNC_C5_PMON_BOX_CTL, 0, 0, 8, 0, 0, 44, MSR_UNC_C5_PMON_BOX_FILTER, MSR_UNC_C5_PMON_BOX_FILTER1},
    [CBOX6] = {MSR_UNC_C6_PMON_BOX_CTL, 0, 0, 9, 0, 0, 44, MSR_UNC_C6_PMON_BOX_FILTER, MSR_UNC_C6_PMON_BOX_FILTER1},
    [CBOX7] = {MSR_UNC_C7_PMON_BOX_CTL, 0, 0, 10, 0, 0, 44, MSR_UNC_C7_PMON_BOX_FILTER, MSR_UNC_C7_PMON_BOX_FILTER1},
    [CBOX8] = {MSR_UNC_C8_PMON_BOX_CTL, 0, 0, 11, 0, 0, 44, MSR_UNC_C8_PMON_BOX_FILTER, MSR_UNC_C8_PMON_BOX_FILTER1},
    [CBOX9] = {MSR_UNC_C9_PMON_BOX_CTL, 0, 0, 12, 0, 0, 44, MSR_UNC_C9_PMON_BOX_FILTER, MSR_UNC_C9_PMON_BOX_FILTER1},
    [CBOX10] = {MSR_UNC_C10_PMON_BOX_CTL, 0, 0, 13, 0, 0, 44, MSR_UNC_C10_PMON_BOX_FILTER, MSR_UNC_C10_PMON_BOX_FILTER1},
    [CBOX11] = {MSR_UNC_C11_PMON_BOX_CTL, 0, 0, 14, 0, 0, 44, MSR_UNC_C11_PMON_BOX_FILTER, MSR_UNC_C11_PMON_BOX_FILTER1},
    [CBOX12] = {MSR_UNC_C12_PMON_BOX_CTL, 0, 0, 15, 0, 0, 44, MSR_UNC_C12_PMON_BOX_FILTER, MSR_UNC_C12_PMON_BOX_FILTER1},
    [CBOX13] = {MSR_UNC_C13_PMON_BOX_CTL, 0, 0, 16, 0, 0, 44, MSR_UNC_C13_PMON_BOX_FILTER, MSR_UNC_C13_PMON_BOX_FILTER1},
    [CBOX14] = {MSR_UNC_C14_PMON_BOX_CTL, 0, 0, 17, 0, 0, 44, MSR_UNC_C14_PMON_BOX_FILTER, MSR_UNC_C14_PMON_BOX_FILTER1},
    [BBOX0] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 18, 1, PCI_HA_DEVICE_0, 48},
    [BBOX1] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 19, 1, PCI_HA_DEVICE_1, 48},
    [SBOX0] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 22, 1, PCI_QPI_DEVICE_PORT_0, 48},
    [SBOX1] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 23, 1, PCI_QPI_DEVICE_PORT_1, 48},
    [SBOX2] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, -1, 1, PCI_QPI_DEVICE_PORT_2, 48},
    [SBOX0FIX] = {0, 0, 0, 0, 1, PCI_QPI_MISC_DEVICE_PORT_0, 64},
    [SBOX1FIX] = {0, 0, 0, 0, 1, PCI_QPI_MISC_DEVICE_PORT_0, 64},
    [SBOX2FIX] = {0, 0, 0, 0, 1, PCI_QPI_MISC_DEVICE_PORT_2, 64},
    [WBOX] = {MSR_UNC_PCU_PMON_BOX_CTL, MSR_UNC_PCU_PMON_BOX_STATUS, MSR_UNC_PCU_PMON_BOX_STATUS, 2, 0, 0, 48,  MSR_UNC_PCU_PMON_BOX_FILTER},
    [WBOX0FIX] = {0, 0, 0, 0, 0, 0, 64},
    [WBOX1FIX] = {0, 0, 0, 0, 0, 0, 64},
    [UBOX] = {0, MSR_UNC_U_PMON_BOX_STATUS, MSR_UNC_U_PMON_BOX_STATUS, 1, 0, 0, 44},
    [UBOXFIX] = {0, MSR_UNC_U_PMON_BOX_STATUS, MSR_UNC_U_PMON_BOX_STATUS, 0, 0, 0, 44},
    [PBOX] = {PCI_UNC_R2PCIE_PMON_BOX_CTL, PCI_UNC_R2PCIE_PMON_BOX_STATUS, PCI_UNC_R2PCIE_PMON_BOX_STATUS, 26, 1,PCI_R2PCIE_DEVICE, 44},
    [RBOX0] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 24, 1,PCI_R3QPI_DEVICE_LINK_0, 44},
    [RBOX1] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 25, 1,PCI_R3QPI_DEVICE_LINK_1, 44},
    [RBOX2] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, -1, 1,PCI_R3QPI_DEVICE_LINK_2, 44},
    [IBOX0] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, -1, 1, PCI_IRP_DEVICE, 44},
    [IBOX1] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, -1, 1, PCI_IRP_DEVICE, 44},
};

static PciDevice ivybridgeEP_pci_devices[MAX_NUM_PCI_DEVICES] = {
 [MSR_DEV] = {NODEVTYPE, "", "", ""},
 [PCI_R3QPI_DEVICE_LINK_0] = {R3QPI, "13.5", "PCI_R3QPI_DEVICE_LINK_0", "RBOX0", 0x0e36},
 [PCI_R3QPI_DEVICE_LINK_1] = {R3QPI, "13.6", "PCI_R3QPI_DEVICE_LINK_1", "RBOX1", 0x0e37},
 [PCI_R3QPI_DEVICE_LINK_2] = {R3QPI, "12.5", "PCI_R3QPI_DEVICE_LINK_2", "RBOX2", 0x0e3e},
 [PCI_R2PCIE_DEVICE] = {R2PCIE, "13.1", "PCI_R2PCIE_DEVICE", "PBOX0", 0x0e34},
 [PCI_IMC_DEVICE_0_CH_0] = {IMC, "10.4", "PCI_IMC_DEVICE_0_CH_0", "MBOX0", 0x0eb4},
 [PCI_IMC_DEVICE_0_CH_1] = {IMC, "10.5", "PCI_IMC_DEVICE_0_CH_1", "MBOX1", 0x0eb5},
 [PCI_IMC_DEVICE_0_CH_2] = {IMC, "10.0", "PCI_IMC_DEVICE_0_CH_2", "MBOX2", 0x0eb0},
 [PCI_IMC_DEVICE_0_CH_3] = {IMC, "10.1", "PCI_IMC_DEVICE_0_CH_3", "MBOX3", 0x0eb1},
 [PCI_HA_DEVICE_0] = {HA, "0e.1", "PCI_HA_DEVICE_0", "BBOX0", 0x0e30},
 [PCI_HA_DEVICE_1] = {HA, "1c.1", "PCI_HA_DEVICE_1", "BBOX1", 0x0e38},
 [PCI_IMC_DEVICE_1_CH_0] = {IMC, "1e.4", "PCI_IMC_DEVICE_1_CH_0", "MBOX4", 0x0ef4},
 [PCI_IMC_DEVICE_1_CH_1] = {IMC, "1e.5", "PCI_IMC_DEVICE_1_CH_1", "MBOX5", 0x0ef5},
 [PCI_IMC_DEVICE_1_CH_2] = {IMC, "1e.0", "PCI_IMC_DEVICE_1_CH_2", "MBOX6", 0x0ef0},
 [PCI_IMC_DEVICE_1_CH_3] = {IMC, "1e.1", "PCI_IMC_DEVICE_1_CH_3", "MBOX7", 0x0ef1},
 [PCI_IRP_DEVICE] = {IRP, "05.6", "PCI_IRP_DEVICE", NULL, 0x0e39},
 [PCI_QPI_DEVICE_PORT_0] = {QPI, "08.2", "PCI_QPI_DEVICE_PORT_0", "SBOX0", 0x0e32},
 [PCI_QPI_DEVICE_PORT_1] = {QPI, "09.2", "PCI_QPI_DEVICE_PORT_1", "SBOX1", 0x0e33},
 [PCI_QPI_DEVICE_PORT_2] = {QPI, "0a.2", "PCI_QPI_DEVICE_PORT_2", "SBOX2", 0x0e3a},
 [PCI_QPI_MASK_DEVICE_PORT_0] = {QPI, "08.6", "PCI_QPI_MASK_DEVICE_PORT_0", NULL, 0x0e86},
 [PCI_QPI_MASK_DEVICE_PORT_1] = {QPI, "09.6", "PCI_QPI_MASK_DEVICE_PORT_1", NULL, 0x0e96},
 [PCI_QPI_MASK_DEVICE_PORT_2] = {QPI, "0a.6", "PCI_QPI_MASK_DEVICE_PORT_2", NULL, 0x0ec6},
 [PCI_QPI_MISC_DEVICE_PORT_0] = {QPI, "08.0", "PCI_QPI_MISC_DEVICE_PORT_0/1", "SBOX01FIX",0x0e80},
 [PCI_QPI_MISC_DEVICE_PORT_2] = {QPI, "0a.0", "PCI_QPI_MISC_DEVICE_PORT_2", "SBOX2FIX", 0x0ec0},
};
