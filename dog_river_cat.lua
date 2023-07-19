-- Solar Solutions
-- File: solarsolutions.lua

-- Create our global table for Solar Solutions
SolarSolutions = {}

-- Define our constants
SolarSolutions.MaximumPower = 1000000 -- Watts
SolarSolutions.MinimumPower = 0 -- Watts
SolarSolutions.DefaultPower = 500000 -- Watts
SolarSolutions.DegreePerKelvin = 0.0001 -- Degrees Celsius per Kelvin

-- Initialize our available modules
SolarSolutions.AvailableModules = {
	{
		name = "Monocrystalline",
		efficiency = 20
	},
	{
		name = "Polycrystalline",
		efficiency = 15
	},
	{
		name = "Organic",
		efficiency = 11
	},
	{
		name = "Amorphous",
		efficiency = 6
	},
}

-- Define our global functions
function SolarSolutions.GetTotalPower( modules )
	-- Initialize our total power
	local total_power = 0

	-- Calculate our total power from the modules
	for i, module in ipairs( modules ) do
		total_power = total_power + ( module.efficiency * SolarSolutions.DefaultPower )
	end

	-- Make sure our total power is within our range
	if total_power > SolarSolutions.MaximumPower then
		total_power = SolarSolutions.MaximumPower
	elseif total_power < SolarSolutions.MinimumPower then
		total_power = SolarSolutions.MinimumPower
	end

	-- Return our total power
	return total_power
end

function SolarSolutions.CalcEfficiencyPerKelvin( modules )
	-- Initialize our total efficiency
	local total_efficiency = 0

	-- Calculate our total efficiency from the modules
	for i, module in ipairs( modules ) do
		total_efficiency = total_efficiency + module.efficiency
	end

	-- Calculate our average efficiency
	local average_efficiency = total_efficiency / #modules

	-- Return our efficiency per kelvin
	return average_efficiency * SolarSolutions.DegreePerKelvin
end

function SolarSolutions.GetAvailableModules()
	-- Return our available modules
	return SolarSolutions.AvailableModules
end

-- Create and return our Solar Solutions instance
function SolarSolutions.Create()
	-- Create our instance
	local instance = {}

	-- Initialize our properties
	instance.Power = SolarSolutions.DefaultPower
	instance.Modules = {}

	-- Define our instance functions
	function instance:AddModule( module )
		-- Add the module to our array
		table.insert( self.Modules, module )
	end

	function instance:RemoveModule( index )
		-- Remove the module from our array
		table.remove( self.Modules, index )
	end

	function instance:GetPower()
		-- Get our total power
		return SolarSolutions.GetTotalPower( self.Modules )
	end

	function instance:GetEfficiencyPerKelvin()
		-- Get our efficiency per kelvin
		return SolarSolutions.CalcEfficiencyPerKelvin( self.Modules )
	end

	-- Return our instance
	return instance
end

-- Return our global table
return SolarSolutions