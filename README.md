# Split Keyboard

## Philosophy

### Layers

The basic principals I followed for the layers was what immediately thought of,

`F` -> keypad layer. (KP)
`D` -> matching pair layer, and arrows. (MP)
`S` -> symbol layer. (SYM)
`A` -> TBD.

> [!NOTE]
>
> The exception to this rule is the function key layer. This is because I never
> use it. I sent it to the most useless key on my board for that reason. 

In order to make the transition from normal `qwerty` to this split layout, I
decided to make my symbol layer match my numbers from the top row of the
`qwerty` boards. E.g. 1 -> !. I tried making a custom symbols layers and it was
incredibly hard to remember what it was. I thought: "Why struggle when I can
just use what I know?"

Of course, some symbols were still missing. I added underscore, tilde, and
backtick to the pinky column. Backtick was placed on the homerow as it is an
incredibly underatted mapping in vim.

### Modifier keys

I use modifier keys extremely frequently. I user a tiling window manager, and
vim on an hourly basis at work. I always wanted `CTL` and `ALT` to be extremely
accessible so I can use `hjkl` to move around my visual space. 

`V, M` -> `CTL` (vim windows)
`C, <` -> `ALT` (TWM windows)
`X, >` -> `SFT`
`Z, ?` -> `WIN`

With this, I have successfully removed the modifier keys from my pinky, which
has been causing me pinky pain for a while now. 

### Thumb Keys

I always look at the Kinesis Advantage and wanted it. But I thought it had too
many keys! That being said, I copied their thumb key layout. Strangely enough, I
only use my right hand to press space bar. It was a pretty easy transition. 

## Responsiveness

### Chordal layout

When using homerow mods for the first time, you get very excited! It is new and
fresh. But, then you misinput the entire first day. What the heck? Why?!?

I will tell you. In `qwerty` keys tend to repeat in the right hand a lot. This
is a whole other controversial thing that we will not get into. In order to deal
with this curse, we can define this setting:

``` c 
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
                       'L', 'L', 'L',  'R', 'R', 'R'
    );
```

> [!NOTE]
> This the handedness for the Silakka54, the board I use.

Also add this into your `config.h`:

``` c 

#define CHORDAL_HOLD
```

This stops the keyboard from 'activating' a layer on the same hand. So, when
we hold `M`, only our left hand will have the `CTL` modifier attached. If you
pressed `k` after holding `M`, the keyboard will send `mk`. Awesome! This
cures our rolling false positive issue. Note that the way you configure your
board should follow this, if you decide to use it. 


### Timeless Homerow Mods with QMK

It took me a long time to find a homerow mod config that didn't result in me
having misinputs throughout the day. I took inspiration from the "Timeless
Homerow Mods" that I have seen online. Unfortunately, this was made in ZMK,
which in my opinion has more granular control over how the homerow mods are
programmed. I decided to take the time and figure out how to do this in QMK. 

Add this to your config.h, we will explain what they do later

``` c                           
                                
#define HOLD_ON_OTHER_KEY_PRESS

#define FLOW_TAP_TERM 125
```

#### HOLD_ON_OTHER_KEY_PRESS


When using layers the process goes:
1. Hold layer key
2. Press desired key
3. Let go of desired key
4. Release layer key

When I type fast though, I get a lot of issues where I do this instead: 
1. Hold layer key
2. Press desired key
3. Release layer key
4. Let go of desired key

Because I think 'I got the key I wanted, lets move on.' 

Here is a more visual representation of that


| Time | Physical Key | Default  | PERMISSIVE_HOLD | HOLD_ON_OTHER_KEY_PRESS |
| --------------- | --------------- | --------------- | --------------- | --------------- |
| 0    | `LSFT_T(KC_A)` down |    |   |  |
| 110  | `KC_B` down       |    |     | B |
| 130  | `LSFT_T(KC_A)` up | ab | ab | B |
| 140  | `KC_B` up | ab | ab | B |


#### FLOW_TAP_TERM

This is QMK's closest equivalent to ZMK's `required-time-idle`. It requires the user to
stop for a bit before using the homerow mod key as its hold property. This
allows us to type as we usually do, only having a slight hiccup when a layer
switch is wanted. This means we can just type normally most of the time. More
research needs to be done here.

