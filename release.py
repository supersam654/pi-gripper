import hardware_api as api

def release_item():
    api.position_bottom_plate_on_ground()
    api.retract_bottom_plate()
    api.retract_top_plate()
    api.retract_claws()
    api.lift_arm()

if __name__ == '__main__':
    release_item()
