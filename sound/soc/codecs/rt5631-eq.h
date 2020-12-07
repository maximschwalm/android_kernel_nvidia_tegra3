/*
 * ASUS tweaks for RT5631 ALSA Soc Audio driver
 *
 * Copyright (c) 2012, ASUSTek Corporation.
 * Copyright (c) 2020, Svyatoslav Ryhel
 * Copyright (c) 2020, Narkolai
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */
#ifndef __RT5631EQ_H
#define __RT5631EQ_H

#define ENABLE_EQ			1
#define ENABLE_ALC			1
#define TF700T_PCB_ER1		0x3

#define RT5631_L_VOL					(0x3f << 8)
#define RT5631_R_VOL					(0x3f)
#define RT5631_DMIC_R_CH_UNMUTE			(0x0 << 12)
#define RT5631_DMIC_L_CH_UNMUTE			(0x0 << 13)

/* Basic EQ init */
int rt5631_reg_init(struct snd_soc_codec *codec);
int codec_3v3_power_switch_init(void);

/* EQ Mode section */
int rt5631_eq_sel_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol);
int rt5631_eq_sel_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol);

/* Recording gain section */
int rt5631_get_gain(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol);
int rt5631_set_gain(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol);

/* Event section */
int spk_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event);
int adc_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event);
int dac_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event);

#endif
