/* Basic multiply node.
 */

static const char *const HELP = "Multiplies the input stream";

#include "DDImage/Knobs.h"
#include "DDImage/NukeWrapper.h"
#include "DDImage/PixelIop.h"
#include "DDImage/Row.h"

using namespace DD::Image;

class Multiply : public PixelIop {

public:
  void in_channels(int input, ChannelSet &mask) const;
  Multiply(Node *node) : PixelIop(node) {
    value[0] = value[1] = value[2] = value[3] = 1;
  }
  bool pass_transform() const { return true; }
  void pixel_engine(const Row &in, int y, int x, int r, ChannelMask, Row &out);
  virtual void knobs(Knob_Callback);
  static const Iop::Description d;
  const char *Class() const { return d.name; }
  const char *node_help() const { return HELP; }
  void _validate(bool);

protected:
  float value[4];
};

void Multiply::_validate(bool for_real) {
  copy_info();
  for (unsigned i = 0; i < 4; i++) {
    if (value[i] != 1.0f) {
      set_out_channels(Mask_All);
      info_.black_outside(false);
      return;
    }
  }
  set_out_channels(Mask_None);
}

void Multiply::in_channels(int input, ChannelSet &mask) const {
  // mask is unchanged
}

void Multiply::pixel_engine(const Row &in, int y, int x, int r,
                            ChannelMask channels, Row &out) {
  foreach (z, channels) {
    const float multiply = value[colourIndex(z)];
    const float *inptr = in[z] + x;
    const float *END = inptr + (r - x);
    float *outptr = out.writable(z) + x;
    while (inptr < END) {
      *outptr++ = *inptr++ * multiply;
    }
  }
}

void Multiply::knobs(Knob_Callback f) {
  AColor_knob(f, value, IRange(0, 4), "value");
}

static Iop *build(Node *node) { return new NukeWrapper(new Multiply(node)); }
const Iop::Description Multiply::d("Multiply", "Color/Math/Multiply", build);
