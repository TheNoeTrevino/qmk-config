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
incredibly underrated mapping in vim.

### Modifier keys

I use modifier keys extremely frequently. I user a tiling window manager, and
vim on an hourly basis at work. I always wanted `CTL` and `ALT` to be extremely
accessible so I can use `hjkl` to move around my visual space. 

`V, M` -> `CTL` (vim windows)

`C, <` -> `ALT` (TWM windows)

`X, >` -> `WIN`

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
                                
#define PERMISSIVE_HOLD
#define RETRO_TAPPING
#define TAPPING_TERM 200
```


#### Permissive Hold

This let us activate a layer and use it instantly. It just requires a slight
change of thinking. It is quite hard to explain, but I think of layers as a long
beep in my head. In the duration of that beep, I can use my layer as a please.
When I want to go back to my default layer, I let it go. This illustration should
be more clear: 

                         TAPPING_TERM   
  +---------------------------|--------+
  | +----------------------+  |        |
  | | LT(2, KC_A)          |  |        |
  | +----------------------+  |        |
  |    +--------------+       |        |
  |    | KC_L         |       |        |
  |    +--------------+       |        |
  +---------------------------|--------+

Despite us doing this before the tapping term ends, we still get the modified
key. Note that it will not work if you do this: 

                         TAPPING_TERM   
  +---------------------------|--------+
  | +-------------+           |        |
  | | LT(2, KC_A) |           |        |
  | +-------------+           |        |
  |       +--------------+    |        |
  |       | KC_L         |    |        |
  |       +--------------+    |        |
  +---------------------------|--------+

In my experience, the above might look like what you want. After you try it, you
might realize that the misfires are border line unbearable. If it is what you
want, you should look into `HOLD_ON_OTHER_KEY_PRESS`.


#### Retro Tapping

This one is pretty simple. When you hold a key, for example: `LT(4, KC_1)`, for an
entire second and do not have another input, the number 1 will then be sent to
the computer. This is just something that I like.

#### Quick Tap Term

When you quickly tap a key twice and hold it, it will now repeat. This is great
for keys like backspace. It is in a prime position (in this keyboard), but you
also want to be able to spam it instead of just holding it for other behavior.
With this you can do both. Just double tap, then hold, to repeat the input. Also
good for something like enter. I only use this for delete, and plan to
experiment with this more in the future.



## Things I want to experiment with

Using quicktap term to make things like `tap`, `enter`, `backspace` modifier
keys. Especially consider making two of the thumb keys shift.
