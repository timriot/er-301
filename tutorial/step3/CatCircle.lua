local app = app
local libFoo = require "tutorial.libFoo"
local Class = require "Base.Class"
local ViewControl = require "Unit.ViewControl"
local ply = app.SECTION_PLY

-- Some background:
-- A unit can have multiple views.
-- A unit view is simply a list of ViewControls.
-- A view always starts with a Header (a type of ViewControl) which is followed by whatever ViewControls instantiated in the unit's onLoadViews method.


-- This class implements a ViewControl that displays a CatCircle graphic and nothing else.
local CatCircle = Class {}
CatCircle:include(ViewControl)

function CatCircle:init(args)
  -- We must have a sequencer or we cannot proceed.
  local sequencer = args.sequencer or
                        app.logError("%s.init: sequencer is missing.", self)

  ViewControl.init(self, "circle")
  self:setClassName("CatCircle")

  -- Some background:
  -- Each display is divided into columns centered above each soft button.
  -- The main display has 6 and the sub display has 3.
  -- The width of one of these columns is 1 ply (or about 42px).

  -- The width of this control defaults to 2 ply.
  local width = args.width or (2 * ply)

  -- Create an empty parent Graphic to hold our CatCircle Graphic.
  local graphic
  graphic = app.Graphic(0, 0, width, 64)
  -- Create the CatCircle
  self.pDisplay = libFoo.CatCircle(0, 0, width, 64)
  -- Add the CatCircle to the parent Graphic.
  graphic:addChild(self.pDisplay)
  -- When this ViewControl gains focus, the system cursor's location should be controlled by the CatCircle graphic.
  self:setMainCursorController(self.pDisplay)
  -- Assign the parent Graphic that we prepared to this ViewControl.
  self:setControlGraphic(graphic)

  -- Define the spots on this ViewControl where the cursor should stop as you scroll horizontally.
  -- Here we simply have the cursor stop at the center of each ply.
  for i = 1, (width // ply) do
    self:addSpotDescriptor{
      center = (i - 0.5) * ply
    }
  end

  -- The sub display is empty for now.
  self.subGraphic = app.Graphic(0, 0, 128, 64)

  -- Configure the CatCircle to render the given sequencer object.
  self:follow(sequencer)
end

function CatCircle:follow(sequencer)
  self.pDisplay:follow(sequencer)
  self.sequencer = sequencer
end

return CatCircle
