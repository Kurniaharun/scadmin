--// UI Script Key System by Laww (No opening animation, copy button shows 'Copied!')

--// Services
local Players = game:GetService("Players")
local player = Players.LocalPlayer
local CoreGui = game:GetService("CoreGui")

-- Remove existing UI jika ada
if CoreGui:FindFirstChild("KeySystemUI") then
    CoreGui.KeySystemUI:Destroy()
end

--// ScreenGui
local gui = Instance.new("ScreenGui", CoreGui)
gui.Name = "KeySystemUI"

--// Frame utama
local mainFrame = Instance.new("Frame", gui)
mainFrame.Size = UDim2.new(0,400,0,250)
mainFrame.Position = UDim2.new(0.5,0,0.5,0)
mainFrame.AnchorPoint = Vector2.new(0.5,0.5)
mainFrame.BackgroundColor3 = Color3.fromRGB(20,20,20)
mainFrame.BorderSizePixel = 0
mainFrame.ClipsDescendants = true
mainFrame.Visible = true

-- Corner
local UICorner = Instance.new("UICorner", mainFrame)
UICorner.CornerRadius = UDim.new(0,12)

-- Header
local header = Instance.new("TextLabel", mainFrame)
header.Size = UDim2.new(1,0,0,40)
header.BackgroundColor3 = Color3.fromRGB(40,40,40)
header.Text = "KEYSYSTEM"
header.TextColor3 = Color3.fromRGB(255,255,255)
header.TextScaled = true
header.Font = Enum.Font.Code
local UICorner2 = Instance.new("UICorner", header)
UICorner2.CornerRadius = UDim.new(0,12)

-- Close Button
local closeBtn = Instance.new("TextButton", mainFrame)
closeBtn.Size = UDim2.new(0,32,0,32)
closeBtn.Position = UDim2.new(1, -40, 0, 4)
closeBtn.AnchorPoint = Vector2.new(0,0)
closeBtn.BackgroundColor3 = Color3.fromRGB(60,60,60)
closeBtn.Text = "✕"
closeBtn.TextColor3 = Color3.fromRGB(255,255,255)
closeBtn.TextScaled = true
closeBtn.Font = Enum.Font.Code
closeBtn.ZIndex = 2
local closeUICorner = Instance.new("UICorner", closeBtn)
closeUICorner.CornerRadius = UDim.new(0, 8)

closeBtn.MouseButton1Click:Connect(function()
    gui:Destroy()
end)

-- Input Key
local keyBox = Instance.new("TextBox", mainFrame)
keyBox.Size = UDim2.new(0.8,0,0,35)
keyBox.Position = UDim2.new(0.1,0,0.3,0)
keyBox.PlaceholderText = "Enter your key..."
keyBox.Text = ""
keyBox.Font = Enum.Font.Code
keyBox.TextScaled = true
keyBox.TextColor3 = Color3.fromRGB(255,255,255)
keyBox.BackgroundColor3 = Color3.fromRGB(30,30,30)
local UICorner3 = Instance.new("UICorner", keyBox)
UICorner3.CornerRadius = UDim.new(0,8)

-- Tombol Submit Key
local submitBtn = Instance.new("TextButton", mainFrame)
submitBtn.Size = UDim2.new(0.35,0,0,35)
submitBtn.Position = UDim2.new(0.1,0,0.5,0)
submitBtn.Text = "Submit Key"
submitBtn.Font = Enum.Font.Code
submitBtn.TextScaled = true
submitBtn.TextColor3 = Color3.fromRGB(255,255,255)
submitBtn.BackgroundColor3 = Color3.fromRGB(0,120,255)
local UICorner4 = Instance.new("UICorner", submitBtn)
UICorner4.CornerRadius = UDim.new(0,8)

-- Tombol Get Key
local getBtn = Instance.new("TextButton", mainFrame)
getBtn.Size = UDim2.new(0.35,0,0,35)
getBtn.Position = UDim2.new(0.55,0,0.5,0)
getBtn.Text = "Get Key"
getBtn.Font = Enum.Font.Code
getBtn.TextScaled = true
getBtn.TextColor3 = Color3.fromRGB(255,255,255)
getBtn.BackgroundColor3 = Color3.fromRGB(0,200,120)
local UICorner5 = Instance.new("UICorner", getBtn)
UICorner5.CornerRadius = UDim.new(0,8)

-- Tombol Buy Premium
local buyBtn = Instance.new("TextButton", mainFrame)
buyBtn.Size = UDim2.new(0.8,0,0,35)
buyBtn.Position = UDim2.new(0.1,0,0.7,0)
buyBtn.Text = "Buy Key Premium"
buyBtn.Font = Enum.Font.Code
buyBtn.TextScaled = true
buyBtn.TextColor3 = Color3.fromRGB(255,255,255)
buyBtn.BackgroundColor3 = Color3.fromRGB(200,50,50)
local UICorner6 = Instance.new("UICorner", buyBtn)
UICorner6.CornerRadius = UDim.new(0,8)

-- Frame Premium
local premiumFrame = Instance.new("Frame", gui)
premiumFrame.Size = UDim2.new(0,400,0,200)
premiumFrame.Position = UDim2.new(0.5,0,0.5,0)
premiumFrame.AnchorPoint = Vector2.new(0.5,0.5)
premiumFrame.BackgroundColor3 = Color3.fromRGB(20,20,20)
premiumFrame.Visible = false
local UICorner7 = Instance.new("UICorner", premiumFrame)
UICorner7.CornerRadius = UDim.new(0,12)

local premTitle = Instance.new("TextLabel", premiumFrame)
premTitle.Size = UDim2.new(1,0,0,40)
premTitle.BackgroundColor3 = Color3.fromRGB(40,40,40)
premTitle.Text = "BUY PREMIUM"
premTitle.TextColor3 = Color3.fromRGB(255,255,255)
premTitle.TextScaled = true
premTitle.Font = Enum.Font.Code
local UICorner8 = Instance.new("UICorner", premTitle)
UICorner8.CornerRadius = UDim.new(0,12)

-- Kontak WA
local wa = Instance.new("TextButton", premiumFrame)
wa.Size = UDim2.new(0.9,0,0,35)
wa.Position = UDim2.new(0.05,0,0.3,0)
wa.Text = "WHATSAPP : +6282281712356 (Copy)"
wa.Font = Enum.Font.Code
wa.TextScaled = true
wa.TextColor3 = Color3.fromRGB(255,255,255)
wa.BackgroundColor3 = Color3.fromRGB(0,120,255)
local UICorner9 = Instance.new("UICorner", wa)
UICorner9.CornerRadius = UDim.new(0,8)

-- Kontak Discord
local disc = Instance.new("TextButton", premiumFrame)
disc.Size = UDim2.new(0.9,0,0,35)
disc.Position = UDim2.new(0.05,0,0.55,0)
disc.Text = "DISCORD : @lawwtod (Copy)"
disc.Font = Enum.Font.Code
disc.TextScaled = true
disc.TextColor3 = Color3.fromRGB(255,255,255)
disc.BackgroundColor3 = Color3.fromRGB(120,0,200)
local UICorner10 = Instance.new("UICorner", disc)
UICorner10.CornerRadius = UDim.new(0,8)

-- Helper: Copy and show 'Copied!' for 1s, then revert
local function copyWithFeedback(btn, text, orig)
    setclipboard(text)
    local old = btn.Text
    btn.Text = orig or "Copied!"
    btn.TextColor3 = Color3.fromRGB(0,255,0)
    btn.AutoButtonColor = false
    task.spawn(function()
        wait(1)
        btn.Text = old
        btn.TextColor3 = Color3.fromRGB(255,255,255)
        btn.AutoButtonColor = true
    end)
end

--// Logic
getBtn.MouseButton1Click:Connect(function()
    copyWithFeedback(getBtn, "https://pastefy.app/G0WGvXXz", "Copied!")
end)

wa.MouseButton1Click:Connect(function()
    copyWithFeedback(wa, "+6282281712356", "Copied!")
end)

disc.MouseButton1Click:Connect(function()
    copyWithFeedback(disc, "@lawwtod", "Copied!")
end)

buyBtn.MouseButton1Click:Connect(function()
    mainFrame.Visible = false
    premiumFrame.Visible = true
end)

submitBtn.MouseButton1Click:Connect(function()
    local key = keyBox.Text
    if key == "Mancing12" or key == "LIFE-01" or key == "LIFE-0" then
        loadstring(game:HttpGet("https://pastefy.app/2oVwuKL4/raw"))()
        gui:Destroy()
    else
        keyBox.Text = "INVALID KEY!"
    end
end)
