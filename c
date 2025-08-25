-- FISH IT SCRIPT - UNIVERSAL ROBLOX LUA (UI iPhone Modern)
-- Fitur: Instant Rail, Auto Rail, Auto Rail V2, Anti Oxygen, Anti Fall, Infinite Jump, Jump Boost, Speed Multiplier, Anti Detect, Teleport Map List, Water Walker

local Players = game:GetService("Players")
local LocalPlayer = Players.LocalPlayer
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")
local Workspace = game:GetService("Workspace")
local TweenService = game:GetService("TweenService")
local ReplicatedStorage = game:GetService("ReplicatedStorage")
local VirtualUser = game:GetService("VirtualUser")

-- Hapus semua UI lama
for _,v in ipairs(game.CoreGui:GetChildren()) do
    if v.Name == "FishItScriptUI" then v:Destroy() end
end

-- UI Baru
local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name = "FishItScriptUI"
ScreenGui.Parent = game.CoreGui
ScreenGui.ResetOnSpawn = false

-- Main Frame (iPhone style)
local MainFrame = Instance.new("Frame")
MainFrame.Size = UDim2.new(0, 280, 0, 400)
MainFrame.Position = UDim2.new(0, 60, 0, 100)
MainFrame.BackgroundColor3 = Color3.fromRGB(25, 25, 30)
MainFrame.BorderSizePixel = 0
MainFrame.Parent = ScreenGui
MainFrame.Active = true
MainFrame.Draggable = true

-- Shadow
local shadow = Instance.new("ImageLabel")
shadow.Name = "Shadow"
shadow.Image = "rbxassetid://1316045217"
shadow.ImageTransparency = 0.6
shadow.Size = UDim2.new(1, 30, 1, 30)
shadow.Position = UDim2.new(0, -15, 0, -15)
shadow.BackgroundTransparency = 1
shadow.Parent = MainFrame
shadow.ZIndex = 0
MainFrame.ZIndex = 1

-- UICorner
local corner = Instance.new("UICorner")
corner.CornerRadius = UDim.new(0, 20)
corner.Parent = MainFrame

-- Judul
local Title = Instance.new("TextLabel")
Title.Size = UDim2.new(1, 0, 0, 50)
Title.Position = UDim2.new(0, 0, 0, 0)
Title.BackgroundColor3 = Color3.fromRGB(45, 45, 60)
Title.Text = "FISH IT SCRIPT"
Title.TextColor3 = Color3.fromRGB(255,255,255)
Title.Font = Enum.Font.GothamBold
Title.TextSize = 24
Title.TextStrokeTransparency = 0.8
Title.TextYAlignment = Enum.TextYAlignment.Center
Title.Parent = MainFrame
local titleCorner = Instance.new("UICorner")
titleCorner.CornerRadius = UDim.new(0, 20)
titleCorner.Parent = Title

-- Minimize Button
local MinBtn = Instance.new("TextButton")
MinBtn.Size = UDim2.new(0, 35, 0, 35)
MinBtn.Position = UDim2.new(1, -45, 0, 7.5)
MinBtn.BackgroundColor3 = Color3.fromRGB(70,70,85)
MinBtn.TextColor3 = Color3.fromRGB(255,255,255)
MinBtn.Font = Enum.Font.GothamBold
MinBtn.TextSize = 24
MinBtn.Text = "-"
MinBtn.Parent = MainFrame
MinBtn.ZIndex = 10
local minCorner = Instance.new("UICorner")
minCorner.CornerRadius = UDim.new(1,0)
minCorner.Parent = MinBtn

-- Floating Show Button (hidden by default)
local ShowBtn = Instance.new("TextButton")
ShowBtn.Size = UDim2.new(0, 45, 0, 45)
ShowBtn.Position = UDim2.new(0, 16, 0, 16)
ShowBtn.BackgroundColor3 = Color3.fromRGB(45, 45, 60)
ShowBtn.Text = "≡"
ShowBtn.TextColor3 = Color3.fromRGB(255,255,255)
ShowBtn.Font = Enum.Font.GothamBold
ShowBtn.TextSize = 30
ShowBtn.Visible = false
ShowBtn.Parent = ScreenGui
local showCorner = Instance.new("UICorner")
showCorner.CornerRadius = UDim.new(1,0)
showCorner.Parent = ShowBtn

MinBtn.MouseButton1Click:Connect(function()
    MainFrame.Visible = false
    ShowBtn.Visible = true
end)
ShowBtn.MouseButton1Click:Connect(function()
    MainFrame.Visible = true
    ShowBtn.Visible = false
end)

-- SCROLLING FRAME
local Scroll = Instance.new("ScrollingFrame")
Scroll.Size = UDim2.new(1, 0, 1, -56)
Scroll.Position = UDim2.new(0, 0, 0, 50)
Scroll.BackgroundTransparency = 1
Scroll.BorderSizePixel = 0
Scroll.CanvasSize = UDim2.new(0,0,0,400)
Scroll.ScrollBarThickness = 8
Scroll.Parent = MainFrame
Scroll.AutomaticCanvasSize = Enum.AutomaticSize.Y
Scroll.VerticalScrollBarInset = Enum.ScrollBarInset.Always

-- Inisialisasi y setelah Scroll
local y = 0
local spacing = 48

-- Helper: Separator
local function createSeparator(y)
    local sep = Instance.new("Frame")
    sep.Size = UDim2.new(1, -40, 0, 2)
    sep.Position = UDim2.new(0, 20, 0, y)
    sep.BackgroundColor3 = Color3.fromRGB(70,70,85)
    sep.BorderSizePixel = 0
    sep.Parent = Scroll
    sep.ZIndex = 2
end

-- Helper: Buat tombol besar dengan toggle/checkbox
local function createToggle(text, state, callback)
    local btn = Instance.new("TextButton")
    btn.Size = UDim2.new(0, 230, 0, 40)
    btn.Position = UDim2.new(0, 25, 0, y)
    btn.BackgroundColor3 = Color3.fromRGB(50, 50, 65)
    btn.Text = ""
    btn.AutoButtonColor = false
    btn.Parent = Scroll
    btn.Font = Enum.Font.Gotham
    btn.TextSize = 18
    btn.TextColor3 = Color3.fromRGB(255,255,255)
    btn.ZIndex = 2
    local corner = Instance.new("UICorner")
    corner.CornerRadius = UDim.new(0, 15)
    corner.Parent = btn
    local lbl = Instance.new("TextLabel")
    lbl.Size = UDim2.new(1, -50, 1, 0)
    lbl.Position = UDim2.new(0, 15, 0, 0)
    lbl.BackgroundTransparency = 1
    lbl.Text = text
    lbl.Font = Enum.Font.Gotham
    lbl.TextSize = 18
    lbl.TextColor3 = Color3.fromRGB(255,255,255)
    lbl.TextXAlignment = Enum.TextXAlignment.Left
    lbl.Parent = btn
    lbl.ZIndex = 3
    local box = Instance.new("Frame")
    box.Size = UDim2.new(0, 28, 0, 28)
    box.Position = UDim2.new(1, -38, 0.5, -14)
    box.BackgroundColor3 = state and Color3.fromRGB(0,220,90) or Color3.fromRGB(70,70,85)
    box.Parent = btn
    box.ZIndex = 3
    local boxCorner = Instance.new("UICorner")
    boxCorner.CornerRadius = UDim.new(1,0)
    boxCorner.Parent = box
    local check = Instance.new("TextLabel")
    check.Size = UDim2.new(1,0,1,0)
    check.BackgroundTransparency = 1
    check.Text = state and "✓" or ""
    check.TextColor3 = Color3.fromRGB(255,255,255)
    check.Font = Enum.Font.GothamBold
    check.TextSize = 20
    check.Parent = box
    check.ZIndex = 4
    btn.MouseButton1Click:Connect(function()
        state = not state
        box.BackgroundColor3 = state and Color3.fromRGB(0,220,90) or Color3.fromRGB(70,70,85)
        check.Text = state and "✓" or ""
        callback(state)
    end)
    y = y + spacing
    createSeparator(y-6)
    return btn, function(val)
        state = val
        box.BackgroundColor3 = state and Color3.fromRGB(0,220,90) or Color3.fromRGB(70,70,85)
        check.Text = state and "✓" or ""
    end
end

-- Helper: Buat tombol besar biasa
local function createButton(text, callback)
    local btn = Instance.new("TextButton")
    btn.Size = UDim2.new(0, 230, 0, 40)
    btn.Position = UDim2.new(0, 25, 0, y)
    btn.BackgroundColor3 = Color3.fromRGB(50, 50, 65)
    btn.Text = text
    btn.Font = Enum.Font.Gotham
    btn.TextSize = 18
    btn.TextColor3 = Color3.fromRGB(255,255,255)
    btn.AutoButtonColor = true
    btn.Parent = Scroll
    local corner = Instance.new("UICorner")
    corner.CornerRadius = UDim.new(0, 15)
    corner.Parent = btn
    btn.MouseButton1Click:Connect(callback)
    y = y + spacing
    createSeparator(y-6)
    return btn
end

-- Helper: Buat input pop-up
local function createInputButton(text, default, onSet)
    local btn = Instance.new("TextButton")
    btn.Size = UDim2.new(0, 230, 0, 40)
    btn.Position = UDim2.new(0, 25, 0, y)
    btn.BackgroundColor3 = Color3.fromRGB(50, 50, 65)
    btn.Text = text..": "..tostring(default)
    btn.Font = Enum.Font.Gotham
    btn.TextSize = 18
    btn.TextColor3 = Color3.fromRGB(255,255,255)
    btn.AutoButtonColor = true
    btn.Parent = Scroll
    local corner = Instance.new("UICorner")
    corner.CornerRadius = UDim.new(0, 15)
    corner.Parent = btn
    btn.MouseButton1Click:Connect(function()
        local input = Instance.new("TextBox")
        input.Size = UDim2.new(0, 140, 0, 35)
        input.Position = UDim2.new(0.5, -70, 0.5, -17.5)
        input.BackgroundColor3 = Color3.fromRGB(255,255,255)
        input.TextColor3 = Color3.fromRGB(30,30,30)
        input.Font = Enum.Font.Gotham
        input.TextSize = 18
        input.Text = ""
        input.PlaceholderText = "Enter value..."
        input.Parent = MainFrame
        input.ClearTextOnFocus = true
        input.ZIndex = 10
        local icorner = Instance.new("UICorner")
        icorner.CornerRadius = UDim.new(0, 10)
        icorner.Parent = input
        input.FocusLost:Connect(function(enter)
            if enter then
                local val = tonumber(input.Text)
                if val then
                    btn.Text = text..": "..tostring(val)
                    onSet(val)
                end
                input:Destroy()
            end
        end)
        input:CaptureFocus()
    end)
    y = y + spacing
    createSeparator(y-6)
    return btn
end

-- State Variables
local instantRailEnabled = false
local autoRailEnabled = false
local autoRailV2Enabled = false -- NEW: Auto Rail V2
local realRailEnabled = false -- NEW: Real Rail Toggle

local speedMultiplierEnabled = false
local antiDetectEnabled = false
-- Anti AFK will be loaded via loadstring
local waterWalkerEnabled = false
local savedPosition = nil
local sellPosition = Vector3.new(49, 17, 2870)

-- Buy Rod System
local buyRodPosition = Vector3.new(120, 5, 2856)

local walkSpeedMultiplier = 3.0

local defaultWalkSpeed = 16

-- Ice Walker System
local iceWalkerEnabled = false
local lastIcePos = nil
local stepDistance = 3 -- jarak antar spawn ice
local iceSize = Vector3.new(5, 1, 5) -- ukuran ice
local iceTransparency = 0.3 -- transparansi ice
local iceLifetime = 3 -- detik sebelum ice hancur

-- Vehicle Boost System
local vehicleBoostEnabled = false
local vehicleBoostSpeed = 10 -- kecepatan default vehicle boost
local defaultVehicleBoostSpeed = 10 -- kecepatan normal default
local vboostConnection = nil

local function spawnIce(pos)
    local ice = Instance.new("Part")
    ice.Size = iceSize
    ice.Anchored = true
    ice.CanCollide = true
    ice.Material = Enum.Material.Ice
    ice.Transparency = iceTransparency
    ice.Color = Color3.fromRGB(200, 255, 255)
    ice.CFrame = CFrame.new(Vector3.new(pos.X, pos.Y - 3, pos.Z)) -- tepat di bawah kaki
    ice.Parent = Workspace
    
    -- Hancurkan setelah beberapa detik
    game:GetService("Debris"):AddItem(ice, iceLifetime)
end

local function enableIceWalker()
    iceWalkerEnabled = true
    if LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
        lastIcePos = LocalPlayer.Character.HumanoidRootPart.Position
    end
end

local function disableIceWalker()
    iceWalkerEnabled = false
    lastIcePos = nil
end

-- Vehicle Boost Functions
local function enableVehicleBoost()
    vehicleBoostEnabled = true
    print("Vehicle Boost enabled - Speed: " .. vehicleBoostSpeed)
end

local function disableVehicleBoost()
    vehicleBoostEnabled = false
    if vboostConnection then
        vboostConnection:Disconnect()
        vboostConnection = nil
    end
    print("Vehicle Boost disabled")
end

local function setVehicleBoostSpeed(speed)
    vehicleBoostSpeed = speed
    print("Vehicle Boost speed set to: " .. vehicleBoostSpeed)
end

local function startVehicleBoost()
    if not vehicleBoostEnabled then return end
    
    local character = LocalPlayer.Character
    if not character then
        warn("Character not found.")
        return
    end

    -- Try to find a vehicle seat the player is sitting in
    local vehicle = nil
    for _, v in ipairs(workspace:GetDescendants()) do
        if v:IsA("VehicleSeat") and v.Occupant == character:FindFirstChildWhichIsA("Humanoid") then
            vehicle = v
            break
        end
    end

    if vehicle then
        if vboostConnection then vboostConnection:Disconnect() end
        vboostConnection = RunService.RenderStepped:Connect(function()
            -- Get camera look direction
            local cam = workspace.CurrentCamera
            local dir = cam.CFrame.LookVector
            vehicle.Velocity = dir * vehicleBoostSpeed * 50 -- 50 is a multiplier for Roblox velocity scale
        end)
        print(LocalPlayer.Name .. " is now boosting their vehicle at speed " .. tostring(vehicleBoostSpeed) .. ".")
    else
        print(LocalPlayer.Name .. " is not in a vehicle.")
    end
end

local function stopVehicleBoost()
    print("stopVehicleBoost() function called!")
    local character = LocalPlayer.Character
    if not character then
        warn("Character not found.")
        return
    end

    -- Try to find a vehicle seat the player is sitting in
    local vehicle = nil
    for _, v in ipairs(workspace:GetDescendants()) do
        if v:IsA("VehicleSeat") and v.Occupant == character:FindFirstChildWhichIsA("Humanoid") then
            vehicle = v
            break
        end
    end

    if vboostConnection then
        vboostConnection:Disconnect()
        vboostConnection = nil
        print("Vehicle boost connection disconnected successfully.")
    else
        print("No vboostConnection found to disconnect.")
    end

    if vehicle then
        vehicle.Velocity = Vector3.new(0, 0, 0)
        print(LocalPlayer.Name .. "'s vehicle boost stopped and velocity reset.")
    else
        print(LocalPlayer.Name .. " is not in a vehicle.")
    end
end

-- Instant Rail Feature
createToggle("INSTANT RAIL", instantRailEnabled, function(val)
    instantRailEnabled = val
    if instantRailEnabled then
        spawn(function()
            while instantRailEnabled do
                local success, error = pcall(function()
                    ReplicatedStorage:WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RE/FishingCompleted"):FireServer()
                end)
                if not success then
                    print("Instant Rail Error:", error)
                end
                wait(0.0)
            end
        end)
    end
end)

-- Auto Rail Feature
createToggle("AUTO RAIL", autoRailEnabled, function(val)
    autoRailEnabled = val
    if autoRailEnabled then
        spawn(function()
            while autoRailEnabled do
                -- Charge Fishing Rod
                local success1, error1 = pcall(function()
                    local args = {
                        1755494068.658928
                    }
                    ReplicatedStorage:WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RF/ChargeFishingRod"):InvokeServer(unpack(args))
                end)
                if not success1 then
                    print("Charge Error:", error1)
                end
                
                wait(0.5) -- Wait for charge
                
                -- Throw fishing rod forward
                local success2, error2 = pcall(function()
                    local args = {
                        12.75006103515625,
                        0.8751817529921768
                    }
                    ReplicatedStorage:WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RF/RequestFishingMinigameStarted"):InvokeServer(unpack(args))
                end)
                if not success2 then
                    print("Throw Error:", error2)
                end
                
                -- Wait 6 seconds before next cycle
                wait(3)
            end
        end)
        print("Auto Rail started - Auto charge and throw every 6 seconds")
    else
        print("Auto Rail stopped")
    end
end)

-- Auto Rail V2 Feature (NEW)
createToggle("AUTO RAIL V2", autoRailV2Enabled, function(val)
    autoRailV2Enabled = val
    if autoRailV2Enabled then
        spawn(function()
            while autoRailV2Enabled do
                -- Try to find the fishing rod tool in backpack or character
                local rod = nil
                if LocalPlayer.Character then
                    for _, tool in ipairs(LocalPlayer.Character:GetChildren()) do
                        if tool:IsA("Tool") and tool.Name:lower():find("rod") then
                            rod = tool
                            break
                        end
                    end
                end
                if not rod and LocalPlayer.Backpack then
                    for _, tool in ipairs(LocalPlayer.Backpack:GetChildren()) do
                        if tool:IsA("Tool") and tool.Name:lower():find("rod") then
                            rod = tool
                            break
                        end
                    end
                end

                -- Equip rod if not equipped
                if rod and (not rod.Parent or rod.Parent ~= LocalPlayer.Character) then
                    pcall(function()
                        rod.Parent = LocalPlayer.Character
                    end)
                end

                -- Simulate click to cast rod (simulate input)
                if rod and rod.Parent == LocalPlayer.Character then
                    pcall(function()
                        -- Try to activate the tool (simulate click)
                        rod:Activate()
                    end)
                end

                -- Wait for a short time, then try to "reel" (simulate click again)
                wait(0.7)
                if rod and rod.Parent == LocalPlayer.Character then
                    pcall(function()
                        rod:Activate()
                    end)
                end

                -- Wait for a bit before next cycle
                wait(2.5)
            end
        end)
        print("Auto Rail V2 started - Simulates tool usage for more legit auto fishing")
    else
        print("Auto Rail V2 stopped")
    end
end)

-- Real Rail Toggle Feature (NEW)
createToggle("REAL RAIL", realRailEnabled, function(val)
    realRailEnabled = val
    if realRailEnabled then
        -- Turn ON auto fishing
        local success, error = pcall(function()
            local args = {
                true
            }
            game:GetService("ReplicatedStorage"):WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RF/UpdateAutoFishingState"):InvokeServer(unpack(args))
        end)
        if success then
            print("Real Rail ON - Auto fishing enabled")
        else
            print("Real Rail Error:", error)
        end
    else
        -- Turn OFF auto fishing
        local success, error = pcall(function()
            local args = {
                false
            }
            game:GetService("ReplicatedStorage"):WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RF/UpdateAutoFishingState"):InvokeServer(unpack(args))
        end)
        if success then
            print("Real Rail OFF - Auto fishing disabled")
        else
            print("Real Rail Error:", error)
        end
    end
end)

-- Speed Multiplier (3x)
createToggle("3x SPEED", speedMultiplierEnabled, function(val)
    speedMultiplierEnabled = val
    if LocalPlayer.Character and LocalPlayer.Character:FindFirstChildOfClass("Humanoid") then
        if speedMultiplierEnabled then
            -- Set walkspeed in a way that is less detectable (simulate gradual increase)
            local hum = LocalPlayer.Character.Humanoid
            local targetSpeed = defaultWalkSpeed * walkSpeedMultiplier
            spawn(function()
                for i = hum.WalkSpeed, targetSpeed, 2 do
                    hum.WalkSpeed = math.min(i, targetSpeed)
                    wait(0.05)
                end
                hum.WalkSpeed = targetSpeed
            end)
        else
            -- Reset to default in a way that is less detectable
            local hum = LocalPlayer.Character.Humanoid
            spawn(function()
                for i = hum.WalkSpeed, defaultWalkSpeed, -2 do
                    hum.WalkSpeed = math.max(i, defaultWalkSpeed)
                    wait(0.05)
                end
                hum.WalkSpeed = defaultWalkSpeed
            end)
        end
    end
end)

-- Ice Walker Toggle
createToggle("ICE WALKER", iceWalkerEnabled, function(val)
    iceWalkerEnabled = val
    if iceWalkerEnabled then
        enableIceWalker()
    else
        disableIceWalker()
    end
end)

-- Vehicle Boost Toggle
createToggle("VEHICLE BOOST", vehicleBoostEnabled, function(val)
    vehicleBoostEnabled = val
    if vehicleBoostEnabled then
        enableVehicleBoost()
    else
        disableVehicleBoost()
    end
end)

-- Vehicle Boost Speed Input
createInputButton("VEHICLE BOOST SPEED", vehicleBoostSpeed, function(val)
    setVehicleBoostSpeed(val)
end)

-- Vehicle Boost Control Buttons
createButton("START VEHICLE BOOST", function()
    if vehicleBoostEnabled then
        startVehicleBoost()
    else
        print("Enable VEHICLE BOOST first!")
    end
end)

createButton("STOP VEHICLE BOOST", function()
    print("STOP VEHICLE BOOST button clicked!")
    if vehicleBoostEnabled then
        print("Vehicle Boost is enabled, calling stopVehicleBoost()...")
        stopVehicleBoost()
    else
        print("Enable VEHICLE BOOST first!")
    end
end)

-- Anti Detect (Simple)
createToggle("ANTI DETECT", antiDetectEnabled, function(val)
    antiDetectEnabled = val
    -- Placeholder: implement anti detect logic here if needed
end)

-- Load Anti AFK
loadstring(game:HttpGet("https://raw.githubusercontent.com/hassanxzayn-lua/Anti-afk/main/antiafkbyhassanxzyn"))();

-- Weather System Variables
local weatherOptions = {"Wind", "Cloudy", "Snow", "Storm", "Radiant"}
local weatherStates = {
    Wind = false,
    Cloudy = false,
    Snow = false,
    Storm = false,
    Radiant = false
}
local weatherConnections = {}

-- Load Weather List Button
createButton("LOAD WEATHER LIST", function()
    -- Create Weather UI
    local WeatherGui = Instance.new("ScreenGui")
    WeatherGui.Name = "WeatherListUI"
    WeatherGui.Parent = game.CoreGui
    WeatherGui.ResetOnSpawn = false
    
    -- Main Weather Frame
    local WeatherFrame = Instance.new("Frame")
    WeatherFrame.Size = UDim2.new(0, 350, 0, 450)
    WeatherFrame.Position = UDim2.new(0.5, -175, 0.5, -225)
    WeatherFrame.BackgroundColor3 = Color3.fromRGB(25, 25, 30)
    WeatherFrame.BorderSizePixel = 0
    WeatherFrame.Parent = WeatherGui
    WeatherFrame.Active = true
    WeatherFrame.Draggable = true
    
    -- Weather Frame Corner
    local weatherFrameCorner = Instance.new("UICorner")
    weatherFrameCorner.CornerRadius = UDim.new(0, 15)
    weatherFrameCorner.Parent = WeatherFrame
    
    -- Weather Title
    local WeatherTitle = Instance.new("TextLabel")
    WeatherTitle.Size = UDim2.new(1, -60, 0, 50)
    WeatherTitle.Position = UDim2.new(0, 0, 0, 0)
    WeatherTitle.BackgroundColor3 = Color3.fromRGB(35, 35, 40)
    WeatherTitle.BorderSizePixel = 0
    WeatherTitle.Text = "🌤️ AUTO BUY WEATHER"
    WeatherTitle.TextColor3 = Color3.fromRGB(255, 255, 255)
    WeatherTitle.TextScaled = true
    WeatherTitle.Font = Enum.Font.GothamBold
    WeatherTitle.Parent = WeatherFrame
    
    local titleCorner = Instance.new("UICorner")
    titleCorner.CornerRadius = UDim.new(0, 15)
    titleCorner.Parent = WeatherTitle
    
    -- Close Button
    local WeatherCloseBtn = Instance.new("TextButton")
    WeatherCloseBtn.Size = UDim2.new(0, 50, 0, 50)
    WeatherCloseBtn.Position = UDim2.new(1, -50, 0, 0)
    WeatherCloseBtn.BackgroundColor3 = Color3.fromRGB(255, 100, 100)
    WeatherCloseBtn.BorderSizePixel = 0
    WeatherCloseBtn.Text = "✕"
    WeatherCloseBtn.TextColor3 = Color3.fromRGB(255, 255, 255)
    WeatherCloseBtn.TextScaled = true
    WeatherCloseBtn.Font = Enum.Font.GothamBold
    WeatherCloseBtn.Parent = WeatherFrame
    
    local closeCorner = Instance.new("UICorner")
    closeCorner.CornerRadius = UDim.new(0, 15)
    closeCorner.Parent = WeatherCloseBtn
    
    WeatherCloseBtn.MouseButton1Click:Connect(function()
        WeatherGui:Destroy()
    end)
    
    -- Weather Scroll Frame
    local WeatherScrollFrame = Instance.new("ScrollingFrame")
    WeatherScrollFrame.Size = UDim2.new(1, -20, 1, -70)
    WeatherScrollFrame.Position = UDim2.new(0, 10, 0, 60)
    WeatherScrollFrame.BackgroundTransparency = 1
    WeatherScrollFrame.BorderSizePixel = 0
    WeatherScrollFrame.ScrollBarThickness = 8
    WeatherScrollFrame.ScrollBarImageColor3 = Color3.fromRGB(100, 100, 100)
    WeatherScrollFrame.Parent = WeatherFrame
    
    -- Create weather toggles
    local yPos = 10
    for i, weatherName in ipairs(weatherOptions) do
        -- Weather Toggle Frame
        local weatherToggleFrame = Instance.new("Frame")
        weatherToggleFrame.Size = UDim2.new(1, -20, 0, 60)
        weatherToggleFrame.Position = UDim2.new(0, 10, 0, yPos)
        weatherToggleFrame.BackgroundColor3 = Color3.fromRGB(40, 40, 45)
        weatherToggleFrame.BorderSizePixel = 0
        weatherToggleFrame.Parent = WeatherScrollFrame
        
        local toggleCorner = Instance.new("UICorner")
        toggleCorner.CornerRadius = UDim.new(0, 10)
        toggleCorner.Parent = weatherToggleFrame
        
        -- Weather Icon/Name
        local weatherLabel = Instance.new("TextLabel")
        weatherLabel.Size = UDim2.new(0.6, 0, 1, 0)
        weatherLabel.Position = UDim2.new(0, 15, 0, 0)
        weatherLabel.BackgroundTransparency = 1
        weatherLabel.Text = "🌤️ " .. weatherName
        weatherLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
        weatherLabel.TextScaled = true
        weatherLabel.Font = Enum.Font.GothamBold
        weatherLabel.TextXAlignment = Enum.TextXAlignment.Left
        weatherLabel.Parent = weatherToggleFrame
        
        -- Toggle Button
        local toggleBtn = Instance.new("TextButton")
        toggleBtn.Size = UDim2.new(0, 80, 0, 40)
        toggleBtn.Position = UDim2.new(1, -90, 0.5, -20)
        toggleBtn.BackgroundColor3 = weatherStates[weatherName] and Color3.fromRGB(0, 200, 0) or Color3.fromRGB(100, 100, 100)
        toggleBtn.BorderSizePixel = 0
        toggleBtn.Text = weatherStates[weatherName] and "ON" or "OFF"
        toggleBtn.TextColor3 = Color3.fromRGB(255, 255, 255)
        toggleBtn.TextScaled = true
        toggleBtn.Font = Enum.Font.GothamBold
        toggleBtn.Parent = weatherToggleFrame
        
        local btnCorner = Instance.new("UICorner")
        btnCorner.CornerRadius = UDim.new(0, 8)
        btnCorner.Parent = toggleBtn
        
        -- Toggle functionality
        toggleBtn.MouseButton1Click:Connect(function()
            weatherStates[weatherName] = not weatherStates[weatherName]
            
            if weatherStates[weatherName] then
                -- Start auto buy for this weather
                toggleBtn.BackgroundColor3 = Color3.fromRGB(0, 200, 0)
                toggleBtn.Text = "ON"
                
                weatherConnections[weatherName] = spawn(function()
                    while weatherStates[weatherName] do
                        local success, error = pcall(function()
                            local args = {weatherName}
                            game:GetService("ReplicatedStorage"):WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RF/PurchaseWeatherEvent"):InvokeServer(unpack(args))
                        end)
                        if not success then
                            print("Weather buy error for " .. weatherName .. ":", error)
                        end
                        wait(5) -- Buy every 5 seconds
                    end
                end)
                print("Auto Buy " .. weatherName .. " started")
            else
                -- Stop auto buy for this weather
                toggleBtn.BackgroundColor3 = Color3.fromRGB(100, 100, 100)
                toggleBtn.Text = "OFF"
                
                if weatherConnections[weatherName] then
                    weatherConnections[weatherName] = nil
                end
                print("Auto Buy " .. weatherName .. " stopped")
            end
        end)
        
        yPos = yPos + 70
    end
    
    -- Update scroll canvas size
    WeatherScrollFrame.CanvasSize = UDim2.new(0, 0, 0, yPos)
    
    print("Weather List UI opened")
end)

-- SELL FISH ALL Button (Manual Sell)
createButton("SELL FISH ALL", function()
    if LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
        savedPosition = LocalPlayer.Character.HumanoidRootPart.CFrame
    end
    if LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
        LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(sellPosition)
    end
    local success, error = pcall(function()
        ReplicatedStorage:WaitForChild("Packages"):WaitForChild("_Index"):WaitForChild("sleitnick_net@0.2.0"):WaitForChild("net"):WaitForChild("RF/SellAllItems"):InvokeServer()
    end)
    if not success then
        print("Manual Sell Error:", error)
    end
    wait(1)
    if savedPosition and LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
        LocalPlayer.Character.HumanoidRootPart.CFrame = savedPosition
    end
end)

-- Buy Rod Toggle (Auto Return to Saved Position) - REMOVED
-- createToggle("AUTO RETURN BUY ROD", buyRodEnabled, function(val)
--     buyRodEnabled = val
--     if buyRodEnabled then
--         print("Auto Return Buy Rod enabled - Will return to saved position after buying rod")
--     else
--         print("Auto Return Buy Rod disabled - Will stay at buy rod location")
--     end
-- end)

-- BUY ROD Button (Simplified - No Auto Return)
createButton("BUY ROD", function()
    -- Teleport to buy rod location
    if LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
        LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(buyRodPosition)
        print("Teleported to buy rod location: " .. tostring(buyRodPosition))
    end
end)

-- Teleport Map List (UI List Map)
local teleportMapListFrame = Instance.new("Frame")
teleportMapListFrame.Size = UDim2.new(0, 220, 0, 260)
teleportMapListFrame.Position = UDim2.new(0.5, -110, 0.5, -130)
teleportMapListFrame.BackgroundColor3 = Color3.fromRGB(35, 35, 50)
teleportMapListFrame.Visible = false
teleportMapListFrame.Parent = MainFrame
teleportMapListFrame.ZIndex = 20
local mapCorner = Instance.new("UICorner")
mapCorner.CornerRadius = UDim.new(0, 15)
mapCorner.Parent = teleportMapListFrame

local mapTitle = Instance.new("TextLabel")
mapTitle.Size = UDim2.new(1, 0, 0, 36)
mapTitle.Position = UDim2.new(0, 0, 0, 0)
mapTitle.BackgroundColor3 = Color3.fromRGB(45, 45, 60)
mapTitle.Text = "TELEPORT MAP LIST"
mapTitle.TextColor3 = Color3.fromRGB(255,255,255)
mapTitle.Font = Enum.Font.GothamBold
mapTitle.TextSize = 18
mapTitle.Parent = teleportMapListFrame
mapTitle.ZIndex = 21

local closeMapBtn = Instance.new("TextButton")
closeMapBtn.Size = UDim2.new(0, 36, 0, 36)
closeMapBtn.Position = UDim2.new(1, -40, 0, 0)
closeMapBtn.BackgroundColor3 = Color3.fromRGB(70,70,85)
closeMapBtn.Text = "X"
closeMapBtn.TextColor3 = Color3.fromRGB(255,255,255)
closeMapBtn.Font = Enum.Font.GothamBold
closeMapBtn.TextSize = 18
closeMapBtn.Parent = teleportMapListFrame
closeMapBtn.ZIndex = 22
local closeMapCorner = Instance.new("UICorner")
closeMapCorner.CornerRadius = UDim.new(1,0)
closeMapCorner.Parent = closeMapBtn

closeMapBtn.MouseButton1Click:Connect(function()
    teleportMapListFrame.Visible = false
end)

-- Player List Frame
local playerListFrame = Instance.new("Frame")
playerListFrame.Size = UDim2.new(0, 220, 0, 260)
playerListFrame.Position = UDim2.new(0.5, -110, 0.5, -130)
playerListFrame.BackgroundColor3 = Color3.fromRGB(35, 35, 50)
playerListFrame.Visible = false
playerListFrame.Parent = MainFrame
playerListFrame.ZIndex = 20
local playerCorner = Instance.new("UICorner")
playerCorner.CornerRadius = UDim.new(0, 15)
playerCorner.Parent = playerListFrame

local playerTitle = Instance.new("TextLabel")
playerTitle.Size = UDim2.new(1, 0, 0, 36)
playerTitle.Position = UDim2.new(0, 0, 0, 0)
playerTitle.BackgroundColor3 = Color3.fromRGB(45, 45, 60)
playerTitle.Text = "PLAYER LIST"
playerTitle.TextColor3 = Color3.fromRGB(255,255,255)
playerTitle.Font = Enum.Font.GothamBold
playerTitle.TextSize = 18
playerTitle.Parent = playerListFrame
playerTitle.ZIndex = 21

local closePlayerBtn = Instance.new("TextButton")
closePlayerBtn.Size = UDim2.new(0, 36, 0, 36)
closePlayerBtn.Position = UDim2.new(1, -40, 0, 0)
closePlayerBtn.BackgroundColor3 = Color3.new(0.8, 0.3, 0.3)
closePlayerBtn.Text = "X"
closePlayerBtn.TextColor3 = Color3.fromRGB(255,255,255)
closePlayerBtn.Font = Enum.Font.GothamBold
closePlayerBtn.TextSize = 18
closePlayerBtn.Parent = playerListFrame
closePlayerBtn.ZIndex = 22
local closePlayerCorner = Instance.new("UICorner")
closePlayerCorner.CornerRadius = UDim.new(1,0)
closePlayerCorner.Parent = closePlayerBtn

closePlayerBtn.MouseButton1Click:Connect(function()
    playerListFrame.Visible = false
end)

local playerScroll = Instance.new("ScrollingFrame")
playerScroll.Size = UDim2.new(1, -16, 1, -46)
playerScroll.Position = UDim2.new(0, 8, 0, 40)
playerScroll.BackgroundTransparency = 1
playerScroll.BorderSizePixel = 0
playerScroll.CanvasSize = UDim2.new(0,0,0,400)
playerScroll.ScrollBarThickness = 8
playerScroll.Parent = playerListFrame
playerScroll.AutomaticCanvasSize = Enum.AutomaticSize.Y
playerScroll.VerticalScrollBarInset = Enum.ScrollBarInset.Always
playerScroll.ZIndex = 21

local mapScroll = Instance.new("ScrollingFrame")
mapScroll.Size = UDim2.new(1, -16, 1, -46)
mapScroll.Position = UDim2.new(0, 8, 0, 40)
mapScroll.BackgroundTransparency = 1
mapScroll.BorderSizePixel = 0
mapScroll.CanvasSize = UDim2.new(0,0,0,400)
mapScroll.ScrollBarThickness = 8
mapScroll.Parent = teleportMapListFrame
mapScroll.AutomaticCanvasSize = Enum.AutomaticSize.Y
mapScroll.VerticalScrollBarInset = Enum.ScrollBarInset.Always
mapScroll.ZIndex = 21

-- Placeholder: Map list, to be filled manually later
local mapList = {
    {name = "Fisherland Island", pos = Vector3.new(34, 12, 2815)},
    {name = "Crater Island", pos = Vector3.new(1011.92, 20.23, 5086.41)},
    {name = "Worm Hunt Island", pos = Vector3.new(-450.16, 18.22, 5218.45)},
    {name = "Kohana", pos = Vector3.new(-634.39, 16.04, 616.81)},
    {name = "Volcano", pos = Vector3.new(-593.46, 59.00, 108.01)},
    {name = "Weather Machine", pos = Vector3.new(-1522.29, 6.41, 1888.76)},
    {name = "Tropical Grove", pos = Vector3.new(-2062.71, 7.46, 3641.72)},
    {name = "Esoteric Depth", pos = Vector3.new(2097.77, -28.55, 1359.98)},
    {name = "Enchant Altar", pos = Vector3.new(3257.22, -1300.65, 1390.06)},
    {name = "Lost Isle", pos = Vector3.new(-3671.37, 6.32, -1059.14)},
    {name = "Treasure Hall", pos = Vector3.new(-3599, -280, -1634)},
}

local function refreshMapList()
    for _,v in pairs(mapScroll:GetChildren()) do
        if v:IsA("TextButton") then v:Destroy() end
    end
    local mapY = 0
    for i, map in ipairs(mapList) do
        local btn = Instance.new("TextButton")
        btn.Size = UDim2.new(1, -10, 0, 36)
        btn.Position = UDim2.new(0, 5, 0, mapY)
        btn.BackgroundColor3 = Color3.fromRGB(50, 50, 65)
        btn.Text = map.name
        btn.Font = Enum.Font.Gotham
        btn.TextSize = 16
        btn.TextColor3 = Color3.fromRGB(255,255,255)
        btn.AutoButtonColor = true
        btn.Parent = mapScroll
        btn.ZIndex = 22
        local btnCorner = Instance.new("UICorner")
        btnCorner.CornerRadius = UDim.new(0, 10)
        btnCorner.Parent = btn
        btn.MouseButton1Click:Connect(function()
            if LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
                LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(map.pos)
            end
            teleportMapListFrame.Visible = false
        end)
        mapY = mapY + 42
    end
    mapScroll.CanvasSize = UDim2.new(0,0,0,mapY+10)
end

-- Function to refresh player list with active players
local function refreshPlayerList()
    -- Clear existing player buttons
    for _,v in pairs(playerScroll:GetChildren()) do
        if v:IsA("TextButton") then v:Destroy() end
    end
    
    local playerY = 0
    local activePlayers = Players:GetPlayers()
    
    for _, player in ipairs(activePlayers) do
        -- Skip local player
        if player ~= LocalPlayer then
            local btn = Instance.new("TextButton")
            btn.Size = UDim2.new(1, -10, 0, 36)
            btn.Position = UDim2.new(0, 5, 0, playerY)
            btn.BackgroundColor3 = Color3.fromRGB(50, 50, 65)
            btn.Text = player.Name
            btn.Font = Enum.Font.Gotham
            btn.TextSize = 16
            btn.TextColor3 = Color3.fromRGB(255,255,255)
            btn.AutoButtonColor = true
            btn.Parent = playerScroll
            btn.ZIndex = 22
            
            local btnCorner = Instance.new("UICorner")
            btnCorner.CornerRadius = UDim.new(0, 10)
            btnCorner.Parent = btn
            
            -- Add player status indicator
            local statusDot = Instance.new("Frame")
            statusDot.Size = UDim2.new(0, 8, 0, 8)
            statusDot.Position = UDim2.new(0, 8, 0.5, -4)
            statusDot.BackgroundColor3 = Color3.fromRGB(0, 255, 0) -- Green for online
            statusDot.Parent = btn
            statusDot.ZIndex = 23
            
            local dotCorner = Instance.new("UICorner")
            dotCorner.CornerRadius = UDim.new(1, 0)
            dotCorner.Parent = statusDot
            
            -- Teleport to player when clicked
            btn.MouseButton1Click:Connect(function()
                if LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
                    if player.Character and player.Character:FindFirstChild("HumanoidRootPart") then
                        local targetPos = player.Character.HumanoidRootPart.Position
                        LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(targetPos + Vector3.new(0, 3, 0))
                        print("Teleported to " .. player.Name)
                        playerListFrame.Visible = false
                    else
                        print("Player " .. player.Name .. " is not loaded yet.")
                    end
                end
            end)
            
            playerY = playerY + 42
        end
    end
    
    -- Update scroll canvas size
    playerScroll.CanvasSize = UDim2.new(0,0,0,playerY+10)
    
    -- Show player count
    print("Player List refreshed: " .. #activePlayers .. " players online")
end

createButton("TELEPORT MAP LIST", function()
    teleportMapListFrame.Visible = true
    refreshMapList()
end)

-- Load Player List Button
createButton("LOAD PLAYER LIST", function()
    playerListFrame.Visible = true
    refreshPlayerList()
end)

-- Status Display
local statusLabel = Instance.new("TextLabel")
statusLabel.Size = UDim2.new(0, 230, 0, 30)
statusLabel.Position = UDim2.new(0, 25, 0, y)
statusLabel.BackgroundColor3 = Color3.fromRGB(40, 40, 55)
statusLabel.Text = "Status: Ready"
statusLabel.TextColor3 = Color3.fromRGB(0, 255, 0)
statusLabel.Font = Enum.Font.Gotham
statusLabel.TextSize = 14
statusLabel.Parent = Scroll
statusLabel.ZIndex = 2
local statusCorner = Instance.new("UICorner")
statusCorner.CornerRadius = UDim.new(0, 10)
statusCorner.Parent = statusLabel

-- Update status function
local function updateStatus(text, color)
    statusLabel.Text = "Status: " .. text
    statusLabel.TextColor3 = color or Color3.fromRGB(0, 255, 0)
end

-- Main loop for status updates and features
RunService.RenderStepped:Connect(function()
    -- Status
    if instantRailEnabled then
        updateStatus("Instant Rail Active", Color3.fromRGB(255, 255, 0))
    elseif autoRailEnabled then
        updateStatus("Auto Rail Active", Color3.fromRGB(0, 255, 255))
    elseif autoRailV2Enabled then
        updateStatus("Auto Rail V2 Active", Color3.fromRGB(0, 200, 255))
    elseif realRailEnabled then
        updateStatus("Real Rail Active", Color3.fromRGB(255, 100, 255))
    elseif speedMultiplierEnabled then
        updateStatus("3x Speed Active", Color3.fromRGB(255, 120, 0))
    elseif iceWalkerEnabled then
        updateStatus("Ice Walker Active", Color3.fromRGB(100, 200, 255))
    elseif vehicleBoostEnabled then
        if vboostConnection then
            updateStatus("Vehicle Boost Active - Boosting", Color3.fromRGB(255, 150, 0))
        else
            updateStatus("Vehicle Boost Active - Ready", Color3.fromRGB(255, 200, 100))
        end
    -- Anti AFK is now loaded via loadstring
    elseif antiDetectEnabled then
        updateStatus("Anti Detect Active", Color3.fromRGB(255, 0, 0))
    else
        -- Check if any weather is active
        local activeWeathers = {}
        for weather, isActive in pairs(weatherStates) do
            if isActive then
                table.insert(activeWeathers, weather)
            end
        end
        
        if #activeWeathers > 0 then
            local weatherText = "Auto Buy: " .. table.concat(activeWeathers, ", ")
            updateStatus(weatherText, Color3.fromRGB(100, 255, 200))
        else
            updateStatus("Ready", Color3.fromRGB(0, 255, 0))
        end
    end

    -- Anti AFK is now handled by separate connection for better performance

    -- Speed Multiplier 3x (anti detect: gradual set)
    if LocalPlayer.Character and LocalPlayer.Character:FindFirstChildOfClass("Humanoid") then
        local hum = LocalPlayer.Character.Humanoid
        if speedMultiplierEnabled then
            if math.abs(hum.WalkSpeed - (defaultWalkSpeed * walkSpeedMultiplier)) > 0.1 then
                -- Gradually set to target speed
                hum.WalkSpeed = hum.WalkSpeed + math.clamp((defaultWalkSpeed * walkSpeedMultiplier) - hum.WalkSpeed, -2, 2)
            end
        else
            if math.abs(hum.WalkSpeed - defaultWalkSpeed) > 0.1 then
                hum.WalkSpeed = hum.WalkSpeed + math.clamp(defaultWalkSpeed - hum.WalkSpeed, -2, 2)
            end
        end
    end

    -- Ice Walker logic
    if iceWalkerEnabled and LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
        local root = LocalPlayer.Character.HumanoidRootPart
        local currentPos = root.Position
        
        if lastIcePos and (currentPos - lastIcePos).Magnitude >= stepDistance then
            spawnIce(currentPos)
            lastIcePos = currentPos
        elseif not lastIcePos then
            lastIcePos = currentPos
        end
    end
end)

-- Infinite Jump Handler
UserInputService.JumpRequest:Connect(function()
    if infJumpEnabled and LocalPlayer.Character and LocalPlayer.Character:FindFirstChildOfClass("Humanoid") then
        LocalPlayer.Character.Humanoid:ChangeState(Enum.HumanoidStateType.Jumping)
    end
end)

-- Character respawn handling
LocalPlayer.CharacterAdded:Connect(function(char)
    char:WaitForChild("HumanoidRootPart")
    local hum = char:FindFirstChildOfClass("Humanoid")
    if hum then
        -- Always re-apply 3x speed multiplier if enabled (anti detect: gradual set)
        if speedMultiplierEnabled then
            spawn(function()
                for i = hum.WalkSpeed, defaultWalkSpeed * walkSpeedMultiplier, 2 do
                    hum.WalkSpeed = math.min(i, defaultWalkSpeed * walkSpeedMultiplier)
                    wait(0.05)
                end
                hum.WalkSpeed = defaultWalkSpeed * walkSpeedMultiplier
            end)
        else
            hum.WalkSpeed = defaultWalkSpeed
        end
    end
end)

print("Fish It Script Loaded Successfully!")
print("Features:")
print("- Instant Rail: Auto execute fishing completed")
print("- Auto Rail: Auto charge and throw every 6 seconds")
print("- Auto Rail V2: Simulates tool usage for more legit auto fishing")
print("- Real Rail: Toggle server-side auto fishing on/off")

print("- Sell Fish All: One-time sell with position save")
print("- Buy Rod: Teleport to buy rod location (120, 5, 2856)")
 
print("- Infinite Jump: Jump unlimited")
print("- Jump Boost: Jump power up")
print("- 3x Speed: Walk speed x3.0 (auto reapply after respawn, anti detect)")
print("- Ice Walker: Spawn ice blocks while walking")

print("- Vehicle Boost: Boost vehicles with adjustable speed")
print("- Anti Detect: Simple anti cheat")
print("- Anti AFK: Loaded via loadstring from hassanxzayn-lua")
print("- Teleport Map List: UI for teleport, add map manual")
print("- Load Player List: Teleport to active players")

-- Cleanup function for script termination
local function cleanup()
    if vboostConnection then
        vboostConnection:Disconnect()
        vboostConnection = nil
    end
    print("Script cleanup completed")
end

-- Connect cleanup to game closing
game:BindToClose(cleanup)
